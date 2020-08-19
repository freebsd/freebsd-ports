# Created by: Brent J. Nordquist <bjn@visi.com>
# $FreeBSD$

PORTNAME=	gdbm
PORTVERSION=	1.18.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	GNU

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNU database manager

LICENSE=	GPLv3+

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool:keepla readline

MAKE_JOBS_UNSAFE=	yes

INFO=		gdbm

OPTIONS_DEFINE=	COMPAT NLS
OPTIONS_SUB=	yes
COMPAT_DESC=	Enable dbm/ndbm compatibility
COMPAT_CONFIGURE_ENABLE=	libgdbm-compat
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

post-patch:
# Fix the build with -fno-common (clang 11 and gcc 10)
	@${REINPLACE_CMD} -e '/^char \*parseopt_program_[ad]/d' \
		${WRKSRC}/src/parseopt.c

.include <bsd.port.mk>
