# New ports collection makefile for:	spacechart
# Date created:				Mon Aug 20 14:50:20 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	spacechart
PORTVERSION=	0.9.4
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOMELIBS=	yes
CONFIGURE_ARGS=	--without-included-gettext --datadir=${PREFIX}/share

# trick it into using ports installed gettext
post-patch:
	@${PERL} -pi -ne "s|(INTLLIBS =).*$$|\1-I${LOCALBASE}/lib -lintl|" \
		${WRKSRC}/src/Makefile.in

pre-build:
	@${RM} -Rf ${WRKSRC}/intl

post-install:
	@${INSTALL_DATA} ${WRKSRC}/doc/sample-spacechartrc ${PREFIX}/etc
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/coordinates.txt \
		${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
