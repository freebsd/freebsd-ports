# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	unnethack
DISTVERSION=	5.1.0-20131208
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	New variant of NetHack

LICENSE=	nethack
LICENSE_NAME=	NETHACK GENERAL PUBLIC LICENSE
LICENSE_FILE=	${WRKSRC}/dat/license
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes
USES=		gmake groff ncurses
MAKE_JOBS_UNSAFE=	yes

VARDIR_REL=	var/games/${PORTNAME}
VARDIR=		${PREFIX}/${VARDIR_REL}
CONFIGURE_ARGS=	--datadir="${DATADIR:H}" \
		--localstatedir="${VARDIR:H}" \
		--docdir="${DOCSDIR:H}" \
		--with-owner=no \
		--with-group=no \
		--enable-data-librarian \
		LFLAGS="${LDFLAGS}"
MAKE_ARGS=	MANPREFIX="${STAGEDIR}${MANPREFIX}"
INSTALL_TARGET=	install manpages
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-deinstall
SUB_LIST=	VARDIR="${VARDIR}"
PLIST_SUB=	VARDIR="${VARDIR_REL}"

OPTIONS_DEFINE=	DOCS

post-patch:
	${MV} ${WRKSRC}/doc/nethack.6 ${WRKSRC}/doc/${PORTNAME}.6

post-install:
	cd ${STAGEDIR}${PREFIX}/man/man6; \
	for f in ${WRKSRC}/doc/*.6; do \
		fn=$${f##*/}; \
		case $$fn in \
			unnethack.6) ;; \
			*) ${MV} $$fn unnethack_$$fn ;; \
		esac; \
	done

post-install-DOCS-on:
	${INSTALL_DATA} ${FILESDIR}/sample.unnethackrc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
