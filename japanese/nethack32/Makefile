# New ports collection makefile for:	nethack
# Date created:		13 February 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	nethack
PORTVERSION=	1.0.5.19970924
PORTREVISION=	4
CATEGORIES=	japanese games
MASTER_SITES=	ftp://ftp.nethack.org/pub/nethack/nh322/src/ \
		ftp://ftp.wtower.com/nethack/sources/
DISTNAME=	${PORTNAME}-3.2.2

PATCH_SITES=	ftp://mitsuko.jaist.ac.jp/pub/nethack/
PATCHFILES=	j${PORTNAME}-${PORTVERSION}.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dungeon explorin', slashin', hackin' game

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

NO_LATEST_LINK=	yes

DOCSDIR=	${PREFIX}/share/doc/ja/nethack
EXAMPLESDIR=	${PREFIX}/share/examples/ja/nethack
.if !defined(NOPORTDOCS)
SUB_FILES=	pkg-message
.endif

.include <bsd.port.pre.mk>

USE_XORG=	xaw xpm
USE_GMAKE=	yes
MAN6=		dlb.6 dgn_comp.6 lev_comp.6 nethack.6 recover.6

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

pre-install:
	@cd ${WRKSRC}/doc; ${CHMOD} 644 *.6
	@cd ${WRKSRC}/doc; ${MAKE} PREFIX=${PREFIX} manpages

post-install:
	${INSTALL_DATA} ${WRKSRC}/win/X11/nh_icon.xpm ${PREFIX}/lib/jnethackdir
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/win/X11/nethack.rc ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/win/X11/JNetHack.ad  ${EXAMPLESDIR}
.for i in ibm nh10
	@${INSTALL_DATA} ${WRKSRC}/win/X11/$i.bdf  ${EXAMPLESDIR}
	@${LOCALBASE}/bin/bdftopcf  ${EXAMPLESDIR}/$i.bdf \
		>  ${EXAMPLESDIR}/$i.pcf
	@${RM}  ${EXAMPLESDIR}/$i.bdf
	${GZIP_CMD}  ${EXAMPLESDIR}/$i.pcf
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/jGuidebook.txt ${DOCSDIR}
	${INSTALL_MAN} ${FILESDIR}/README ${DOCSDIR}
.for i in README.j ChangeLog.j INSTALL.j
	${INSTALL_MAN} ${WRKSRC}/$i ${DOCSDIR}
.endfor
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
