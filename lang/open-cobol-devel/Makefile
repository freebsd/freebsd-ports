# ex:ts=8
# Ports collection makefile for:	open-cobol
# Date created:			Aug 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	open-cobol
PORTVERSION=	0.9.7
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	An open-source COBOL compiler

LIB_DEPENDS=	intl:${PORTSDIR}/devel/gettext \
		iconv:${PORTSDIR}/converters/libiconv \
		gnugetopt:${PORTSDIR}/devel/libgnugetopt \
		db4:${PORTSDIR}/databases/db4 \
		gmp.6:${PORTSDIR}/math/libgmp4

USE_REINPLACE=	yes
USE_BISON=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt -lintl"
CONFIGURE_ARGS=	--with-readline
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|-ldb|-ldb4|g" ${WRKSRC}/configure

.include <bsd.port.mk>
