# New ports collection makefile for:	nethack
# Date created:		13 February 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	nethack
PORTVERSION=	1.0.5.19970924
PORTREVISION=	1
CATEGORIES=	japanese games
MASTER_SITES=	ftp://ftp.nethack.org/pub/nethack/nh322/src/ \
		ftp://ftp.wtower.com/nethack/sources/
DISTNAME=	${PORTNAME}-3.2.2

PATCH_SITES=	ftp://mitsuko.jaist.ac.jp/pub/nethack/
PATCHFILES=	j${PORTNAME}-${PORTVERSION}.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dungeon explorin', slashin', hackin' game

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

NO_LATEST_LINK=	yes

.include <bsd.port.pre.mk>

USE_XPM=	yes
USE_GMAKE=	yes
MAN6=		dlb.6 dgn_comp.6 lev_comp.6 nethack.6 recover.6

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

pre-install:
	@cd ${WRKSRC}/doc; ${CHMOD} 644 *.6
	@cd ${WRKSRC}/doc; ${MAKE} PREFIX=${PREFIX} manpages

post-install:
	${INSTALL_DATA} ${WRKSRC}/win/X11/nh_icon.xpm ${PREFIX}/lib/jnethackdir
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/nethack
	${INSTALL_MAN} ${WRKSRC}/doc/jGuidebook.txt ${PREFIX}/share/doc/ja/nethack
	${INSTALL_MAN} ${FILESDIR}/README ${PREFIX}/share/doc/ja/nethack
.for i in README.j ChangeLog.j INSTALL.j
	${INSTALL_MAN} ${WRKSRC}/$i ${PREFIX}/share/doc/ja/nethack
.endfor
.endif
	${MKDIR} ${PREFIX}/share/examples/ja/nethack
	${INSTALL_DATA} ${WRKSRC}/win/X11/nethack.rc ${PREFIX}/share/examples/ja/nethack
	${INSTALL_DATA} ${WRKSRC}/win/X11/JNetHack.ad ${PREFIX}/share/examples/ja/nethack
.for i in ibm nh10
	${INSTALL_DATA} ${WRKSRC}/win/X11/$i.bdf ${PREFIX}/share/examples/ja/nethack
	${X11BASE}/bin/bdftopcf ${PREFIX}/share/examples/ja/nethack/$i.bdf \
		> ${PREFIX}/share/examples/ja/nethack/$i.pcf
	${RM} ${PREFIX}/share/examples/ja/nethack/$i.bdf
	${GZIP_CMD} ${PREFIX}/share/examples/ja/nethack/$i.pcf
.endfor
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
