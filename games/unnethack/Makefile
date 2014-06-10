# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	unnethack
PORTVERSION=	4.0.0.20120401
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A new variant of NetHack

GNU_CONFIGURE=	yes
USES=		gmake
MAKE_JOBS_UNSAFE=	yes

VARDIR_REL=	var/games/${PORTNAME}
VARDIR=		${PREFIX}/${VARDIR_REL}
CONFIGURE_ARGS=	--datadir="${DATADIR:H}" --localstatedir="${VARDIR:H}" --docdir="${DOCSDIR:H}" \
		--with-owner=no --with-group=no \
		--enable-data-librarian
MAKE_ARGS=	MANPREFIX="${STAGEDIR}${MANPREFIX}"
INSTALL_TARGET=	install manpages
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-deinstall
SUB_LIST=	VARDIR="${VARDIR}"
PLIST_SUB=	VARDIR="${VARDIR_REL}"

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
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${FILESDIR}/sample.unnethackrc ${STAGEDIR}${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
