# New ports collection makefile for:	nethack
# Version required:	3.2.2 + 1.0.5.19970924
# Date created:		13 February 1995
# Whom:			asami
#
# $Id: Makefile,v 1.24 1998/11/22 15:40:14 flathill Exp $
#

DISTNAME=	nethack-3.2.2
PKGNAME=	ja-nethack-1.0.5.19970924
CATEGORIES=	japanese games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	nethack

PATCH_SITES=	ftp://mitsuko.jaist.ac.jp/pub/nethack/
PATCHFILES=	jnethack-1.0.5.19970924.gz

MAINTAINER=	max@FreeBSD.ORG

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
MAN6=		dlb.6 dgn_comp.6 lev_comp.6 nethack.6 recover.6

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

pre-install:
	@cd ${WRKSRC}/doc; chmod 644 *.6
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
	${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
