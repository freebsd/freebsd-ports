PORTNAME=	xboard-devel
PORTVERSION=	4.8.0.20151020.3
PORTREVISION=	0
PORTEPOCH=	0
MASTER_SITES=	http://freeheimdall.spdns.org/files/
# http://hgm.nubati.net/cgi-bin/gitweb.cgi?p=xboard.git;a=snapshot;h=${COMMIT_HASH};sf=tgz
# http://hgm.nubati.net/cgi-bin/gitweb.cgi/xboard.git/snapshot/${COMMIT_HASH}
# but sha256 changes, as creation date of *.tar inside *.tar.gz changes.
DISTNAME=	xboard-${COMMIT_HASH}

MAINTAINER=	kalten@gmx.at

LICENSE=	GPLv3

LIB_DEPENDS?=	libpangocairo-1.0.so:x11-toolkits/pango

CONFLICTS=	xboard-[0-9]*

MASTERDIR=	${.CURDIR}/../xboard
DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/files
PLIST=	${.CURDIR}/pkg-plist

COMMIT_HASH=	f49e7e1
DATADIR=	${PREFIX}/share/games/xboard
DOCSDIR=	${PREFIX}/share/doc/xboard
XBOARDCONF=	${WRKSRC}/xboard.conf

USES=		autoreconf desktop-file-utils gettext-tools gmake shared-mime-info shebangfix
SHEBANG_FILES=	texi2man

INSTALL_TARGET=	install-strip

pre-configure:
	${RM} ${WRKSRC}/m4/*.m4
	${REINPLACE_CMD} -e "s|\(GITVERSION=\).*|\1${COMMIT_HASH}|" ${WRKSRC}/Makefile.am
	${REINPLACE_CMD} -E "s|(AC_INIT\(\[xboard\],\[)[^]]+(\].+\))|\1${PORTVERSION}-git:${COMMIT_HASH}\2|" ${WRKSRC}/configure.ac

.include "${MASTERDIR}/Makefile"
