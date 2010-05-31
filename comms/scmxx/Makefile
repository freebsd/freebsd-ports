# New ports collection makefile for:    scmxx
# Date created:         21.03.2002
# Whom:                 Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	scmxx
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Data exchange utility for Siemens mobile phones

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		scmxx.1
MANLANG=	"" ru de it
DOCS=		README docs/*.txt
EXAMPLES=	sms.txt vCalendar.vcs vCard.vcf

post-patch:
	@${FIND} ${WRKSRC} -name 'Makefile*' | ${XARGS} \
		${REINPLACE_CMD} -e "s|CFLAGS=|CFLAGS+=|g"

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
