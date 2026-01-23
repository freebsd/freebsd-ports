PORTNAME=	fnc
DISTVERSION=	0.18
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://fnc.bsdbox.org/tarball/${DISTVERSION}/ \
		https://distfiles.pirateparty.in/ashish/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Interactive ncurses browser for Fossil repositories
WWW=		https://fnc.bsdbox.org/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USES=		localbase:ldflags ncurses
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-Wno-error=gnu-statement-expression

PLIST_FILES=	bin/fnc \
		share/man/man1/fnc.1.gz

# For patch application
post-extract:
	${RM} ${WRKSRC}/lib/sqlite3.*
	${REINPLACE_CMD} -e '/^VERSION/s/${DISTVERSION}$$/%%VERSION%%/' \
		${WRKSRC}/fnc.bld.mk

pre-build:
	${REINPLACE_CMD} -e '/^VERSION/s/%%VERSION%%/${DISTVERSION}/' \
		-e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/fnc.bld.mk

.include <bsd.port.mk>
