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

MAINTAINER=	k5@cheerful.com

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_IMAKE=	YES
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"
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

.if defined(WITH_ESOUND)
LIB_DEPENDS+=	esd.2:${PORTSDIR}/audio/esound
.endif

pre-configure:
.if defined(WITH_ESOUND)
	${MV} ${WRKSRC}/config.h ${WRKSRC}/config.h.orig
	${SED} -e 43,43d -e 45,45d ${WRKSRC}/config.h.orig > ${WRKSRC}/config.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsystem35 ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/../contrib/instgame ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ja/xsystem35
	@(cd ${WRKSRC}/../doc;\
		${INSTALL_MAN} ${DOC_FILES} ${PREFIX}/share/doc/ja/xsystem35)
.endif
	@${MKDIR} ${PREFIX}/share/examples/xsystem35
	@${INSTALL_DATA} ${WRKSRC}/xsys35rc.sample ${PREFIX}/share/examples/xsystem35
	@(cd ${WRKSRC}/../contrib; \
		${INSTALL_DATA} ${EXAMPLES} ${PREFIX}/share/examples/xsystem35)
	@${SED} -e s,PREFIX,${PREFIX}, ${PKGDIR}/MESSAGE > ${WRKSRC}/MESSAGE
	@${CAT} ${WRKSRC}/MESSAGE

.include <bsd.port.post.mk>
