PORTNAME=	mit-scheme
PORTVERSION=	12.1
CATEGORIES=	lang scheme
MASTER_SITES=	GNU/mit-scheme/stable.pkg/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-${MIT_SCHEME_ARCH}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	MIT Scheme: includes runtime, compiler, and edwin binaries
WWW=		https://www.gnu.org/software/mit-scheme/

LICENSE=	GPLv2

BUILD_DEPENDS=	as:devel/binutils

ONLY_FOR_ARCHS=	amd64
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool ncurses
WRKSRC=		${WRKDIR}/mit-scheme-${PORTVERSION}/src/

OPTIONS_DEFINE=		BLOWFISH EDWIN GDBM IMAIL PGSQL X11
OPTIONS_DEFAULT=	BLOWFISH EDWIN GDBM IMAIL PGSQL X11
OPTIONS_SUB=		yes

IMAIL_IMPLIES=	EDWIN
BLOWFISH_DESC=	blowfish library support
GDBM_DESC=	gdbm library support
EDWIN_DESC=	Edwin editor support
IMAIL_DESC=	Imail mail reader support
PGSQL_DESC=	pgsql library support
X11_DESC=	X11 graphics support

BLOWFISH_CONFIGURE_ENABLE=	blowfish
BLOWFISH_CONFIGURE_OFF=		--disable-blowfish
GDBM_CONFIGURE_ENABLE=		gdbm
GDBM_CONFIGURE_OFF=		--disable-gdbm
EDWIN_CONFIGURE_ENABLE=		edwin
EDWIN_CONFIGURE_OFF=		--disable-edwin
IMAIL_CONFIGURE_ENABLE=		imail
IMAIL_CONFIGURE_OFF=		--disable-imail
PGSQL_CONFIGURE_ENABLE=		pgsql
PGSQL_CONFIGURE_OFF=		--disable-pgsql
X11_CONFIGURE_ENABLE=		x11
X11_CONFIGURE_OFF=		--disable-x11

BLOWFISH_USES=	makeinfo
GDBM_USES=	localbase:ldflags makeinfo
PGSQL_USES=	pgsql pkgconfig
X11_USES=	xorg
X11_USE=	XORG=x11

GDBM_LIB_DEPENDS+=	libgdbm.so:databases/gdbm

.include <bsd.port.pre.mk>

MIT_SCHEME_ARCH=	x86-64

PLIST_SUB+=	MIT_SCHEME_ARCH=${MIT_SCHEME_ARCH} \
		PORTVERSION=${PORTVERSION}

do-build:
	@cd ${WRKDIR}/mit-scheme-${PORTVERSION}/src && ${MAKE_CMD}

post-build:
	@${FIND} ${WRKDIR} -type d -empty -delete

do-install:
	@cd ${WRKDIR}/mit-scheme-${PORTVERSION}/src && ${MAKE_CMD} install DESTDIR=${STAGEDIR}
	${INSTALL_MAN} ${WRKDIR}/mit-scheme-${PORTVERSION}/doc/mit-scheme.1 ${STAGEDIR}${PREFIX}/share/man/man1/

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/lib -name "*-shim.so" -exec ${STRIP_CMD} {} \;

.include <bsd.port.post.mk>
