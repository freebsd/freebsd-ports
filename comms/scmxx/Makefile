# New ports collection makefile for:    scmxx
# Date created:         21.03.2002
# Whom:                 Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	scmxx
PORTVERSION=	0.6.4.1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scmxx

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Data exchange utility for Siemens mobile phones

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes

MAN1=		scmxx.1
#MANLANG=	"" ru

.ifndef(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
.for file in sms.txt vCalendar.vcs vCard.vcf
	${INSTALL_DATA} ${WRKSRC}/examples/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
