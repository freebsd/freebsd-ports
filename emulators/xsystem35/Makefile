# ports collection makefile for:	AliceSoft System 3.5 on X
# Date created:		24 Oct 1998
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	xsystem35
PORTVERSION=	1.2.5.1
CATEGORIES=	emulators
MASTER_SITES=	http://www.aist-nara.ac.jp/~masaki-c/private/unitbase/xsys35/down/
DISTNAME=	${PORTNAME}-1.2.5-1

MAINTAINER=	sf@FreeBSD.org

USE_IMAKE=	yes
USE_GTK=	yes
WANT_ESOUND=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src

PKGMESSAGE=	${WRKSRC}/MESSAGE

DOC_FILES=	BUGS ChangeLog FAQ GRFMT.TXT INSTALL MISCGAME.TXT README \
		README.color README.joystick README.miko README.music \
		README.pastel THANKS TODO
EXAMPLES=	README.TXT ambi.inf atlach.inf dalk.inf darcrows.inf \
		diabo.inf drstop.inf hushaby.inf katsumi.inf kichiku.inf \
		mamatoto.inf mamori.inf miko.inf mugen.inf ningen.inf \
		oudou.inf panyo.inf pascha.inf progood.inf rance1.inf \
		rance2.inf rance3.inf rance4.inf toushin.inf toushin2.inf \
		zero.inf

.include <bsd.port.pre.mk>

.if defined(HAVE_ESOUND)
USE_ESOUND=	yes
pre-configure:
	${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.orig
	${SED} -e 43,43d -e 45,45d ${WRKSRC}/config.h.orig > ${WRKSRC}/config.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsystem35 ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/../contrib/instgame ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ja/xsystem35
	(cd ${WRKSRC}/../doc;\
		${INSTALL_MAN} ${DOC_FILES} ${PREFIX}/share/doc/ja/xsystem35)
.endif
	@${MKDIR} ${PREFIX}/share/examples/xsystem35
	${INSTALL_DATA} ${WRKSRC}/xsys35rc.sample ${PREFIX}/share/examples/xsystem35
	@(cd ${WRKSRC}/../contrib; \
		${INSTALL_DATA} ${EXAMPLES} ${PREFIX}/share/examples/xsystem35)
	@${SED} -e s,PREFIX,${PREFIX}, ${PKGDIR}/pkg-message > ${WRKSRC}/MESSAGE
	@${CAT} ${WRKSRC}/MESSAGE

.include <bsd.port.post.mk>
