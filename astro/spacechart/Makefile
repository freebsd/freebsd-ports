# New ports collection makefile for:	spacechart
# Date created:				Mon Aug 20 14:50:20 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	spacechart
PORTVERSION=	0.9.2
CATEGORIES=	astro
MASTER_SITES=	http://zipi.fi.upm.es/~e970095/spacechart/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pat@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOMELIBS=	yes
CONFIGURE_ARGS=	--without-included-gettext

# trick it into using ports installed gettext
post-patch:
	@${PERL} -pi -ne "s|(INTLLIBS =).*$$|\1-I${LOCALBASE}/lib -lintl|" \
		${WRKSRC}/src/Makefile.in

pre-build:
	@${RM} -Rf ${WRKSRC}/intl

.include <bsd.port.mk>
