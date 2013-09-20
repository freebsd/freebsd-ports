# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	unnethack
PORTVERSION=	4.0.0.20120401
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A new variant of NetHack

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_JOBS_UNSAFE=	yes

VARDIR_REL=	var/games/${PORTNAME}
VARDIR=		${PREFIX}/${VARDIR_REL}
CONFIGURE_ARGS=	--datadir="${DATADIR:H}" --localstatedir="${VARDIR:H}" --docdir="${DOCSDIR:H}" \
		--with-owner=games --with-group=games \
		--enable-data-librarian
MAKE_ARGS=	FILEPERM=0664 \
		VARFILEPERM=0664 \
		VARDIRPERM=0775
INSTALL_TARGET=	install manpages
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-deinstall
SUB_LIST=	VARDIR="${VARDIR}"
PLIST_SUB=	VARDIR="${VARDIR_REL}"
# This port accually conflicts with other nethack variant ports on
# these commands that are only significant for those who want to
# "hack" the game in deep.
MAN6=		dgn_comp.6 dlb.6 lev_comp.6 recover.6 ${PORTNAME}.6

NO_STAGE=	yes
post-patch:
	${MV} ${WRKSRC}/doc/nethack.6 ${WRKSRC}/doc/${PORTNAME}.6

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${FILESDIR}/sample.unnethackrc ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
