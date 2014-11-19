# $FreeBSD$

PORTNAME=	xboard-devel
PORTVERSION=	4.7.3.20140909.8
PORTREVISION=
PORTEPOCH=
MASTER_SITES=	http://freeheimdall.spdns.org/files/
# http://hgm.nubati.net/cgi-bin/gitweb.cgi?p=xboard.git;a=snapshot;h=${COMMIT_HASH};sf=tgz
# http://hgm.nubati.net/cgi-bin/gitweb.cgi/xboard.git/snapshot/${COMMIT_HASH}
# but sha256 changes, as creation date of *.tar inside *.tar.gz changes.
DISTNAME=	xboard-${COMMIT_HASH}

MAINTAINER=	kalten@gmx.at

LICENSE=	GPLv3

CONFLICTS=	xboard-[0-9]*

MASTERDIR=	${.CURDIR}/../xboard
DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/files
PLIST=	${.CURDIR}/pkg-plist

COMMIT_HASH=	e677df0
DATADIR=	${PREFIX}/share/games/xboard
DOCSDIR=	${PREFIX}/share/doc/xboard
XBOARDCONF=	${WRKSRC}/xboard.conf.in

USES+=	gmake
USE_AUTOTOOLS=	automake aclocal

INSTALL_TARGET=	install-strip

pre-configure:
	${REINPLACE_CMD} -e "s|\(GITVERSION=\).*|\1${COMMIT_HASH}|" ${WRKSRC}/Makefile.am
	${REINPLACE_CMD} -E "s|(AC_INIT\(\[xboard\],\[master-[^]]+)(\].+\))|\1-git:${COMMIT_HASH}\2|" ${WRKSRC}/configure.ac
	@cd ${WRKSRC} && ./autogen.sh

.include "${MASTERDIR}/Makefile"
