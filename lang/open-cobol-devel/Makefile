# ex:ts=8
# Ports collection makefile for:	open-cobol
# Date created:			Aug 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	open-cobol
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	db4.0:${PORTSDIR}/databases/db4 \
		intl.4:${PORTSDIR}/devel/gettext \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		ltdl.1:${PORTSDIR}/devel/libtool \
		gmp.6:${PORTSDIR}/math/libgmp4

USE_BISON=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt -lintl"
CONFIGURE_ARGS=	--with-readline
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|-ldb|-ldb4|g" ${WRKSRC}/configure

.include <bsd.port.mk>
