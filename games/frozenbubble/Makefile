# New ports collection makefile for:   frozen-bubble
# Date created:        2002-10-06
# Whom:                Klaus Goger <klaus.goger@reflex.at>
#
# $FreeBSD$
#

PORTNAME=	frozenbubble
PORTVERSION=	2.0.0
PORTREVISION=	0
CATEGORIES=	games
MASTER_SITES=	http://www.frozen-bubble.org/data/
DISTNAME=	frozen-bubble-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Throw colourful bubbles to build groups and destroy the groups

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SDL_perl.pm:${PORTSDIR}/devel/p5-SDL
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SDL_perl.pm:${PORTSDIR}/devel/p5-SDL

USE_SDL=	mixer sdl pango
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes

USE_PERL5=	yes
PERL_CONFIGURE=	yes

CONFIGURE_WRKSRC=	${WRKSRC}/c_stuff
REINPLACE_ARGS=	-i ""

MAN6=		frozen-bubble-editor.6 frozen-bubble.6

LEXECDIR=	${PREFIX}/libexec/${PORTNAME}

# XXX: exists untill it will be committed to bsd.port.mk
COPYTREE_SHARE=	${SH} -c '(${FIND} -d $$0 $$2 | ${CPIO} -dumpl $$1 >/dev/null \
		2>&1) && \
		${CHOWN} -R ${SHAREOWN}:${SHAREGRP} $$1 && \
		${FIND} $$1/ -type d -exec ${CHMOD} 755 {} \; && \
		${FIND} $$1/ -type f -exec ${CHMOD} ${SHAREMODE} {} \;' --

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

.include <bsd.port.mk>
