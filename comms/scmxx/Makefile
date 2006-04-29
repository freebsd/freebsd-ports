# New ports collection makefile for:    scmxx
# Date created:         21.03.2002
# Whom:                 Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	scmxx
PORTVERSION=	0.9.0
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Data exchange utility for Siemens mobile phones

USE_BZIP2=	yes
USE_GCC=	3.4+
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

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
