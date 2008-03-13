# New ports collection makefile for:   frozen-bubble
# Date created:        2002-10-06
# Whom:                Klaus Goger <klaus.goger@reflex.at>
#
# $FreeBSD$
#

PORTNAME=	frozenbubble
PORTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.frozen-bubble.org/data/
DISTNAME=	frozen-bubble-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Throw colourful bubbles to build groups and destroy the groups

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SDL_perl.pm:${PORTSDIR}/devel/p5-SDL
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SDL_perl.pm:${PORTSDIR}/devel/p5-SDL \
		${SITE_PERL}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext

USE_SDL=	mixer sdl pango
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
PERL_CONFIGURE=	yes

CONFIGURE_WRKSRC=	${WRKSRC}/c_stuff
REINPLACE_ARGS=	-i ""

MAN6=		frozen-bubble-editor.6 frozen-bubble.6

LEXECDIR=	${PREFIX}/libexec/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600020
IGNORE=		doesn't work unless MSG_NOSIGNAL is defined (FreeBSD version 600020 and higher)
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|\${SDL_CONFIG}|g' \
		${WRKSRC}/c_stuff/Makefile.PL
	@${REINPLACE_CMD} -E -e \
		"s,^(\\\$$FPATH[[:space:]]+=[[:space:]]+).*,\1'${DATADIR}';," \
		-e \
		"s,^(\\\$$FLPATH[[:space:]]+=[[:space:]]+).*,\1'${LEXECDIR}';,"\
		${WRKSRC}/c_stuff/lib/fb_stuff.pm

do-install:
	cd ${WRKSRC}/c_stuff && ${GMAKE} install
	cd ${WRKSRC}/po && ${GMAKE} install

	${INSTALL_SCRIPT} ${BUILD_WRKSRC}/frozen-bubble ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${BUILD_WRKSRC}/frozen-bubble-editor ${PREFIX}/bin/

	${INSTALL_MAN} ${MAN6:S,^,${WRKSRC}/doc/,} ${PREFIX}/man/man6/

	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "gfx snd data" ${DATADIR}/)

	${MKDIR} ${LEXECDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/server/fb-server ${LEXECDIR}/

post-install:

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
