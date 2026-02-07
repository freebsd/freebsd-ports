PORTNAME=	kanatest
PORTVERSION=	0.4.10.g20200611
PORTREVISION=	3
CATEGORIES=	games japanese

MAINTAINER=	Clockwork6400@protonmail.com
COMMENT=	Japanese kana (Hiragana and Katakana) simple flashcard tool
WWW=		https://kanatest.sourceforge.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

FETCH_DEPENDS=	git:devel/git
LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		gettext gmake gnome pkgconfig tar:xz
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 libxml2 pango
GNU_CONFIGURE=	yes
MAKE_ENV=	LIBINTL="-lintl"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

# this will break when upstream is updating, but unfortunately
# SF won't let us fetch individual commits.
do-fetch:
	@${MKDIR} ${_DISTDIR}
	@cd ${_DISTDIR} && [ -f ${DISTNAME}.tar.xz ] || \
	    git archive --format=tar --prefix=${DISTNAME}/ \
	    --remote=git://git.code.sf.net/p/kanatest/code master | \
	    ${XZ_CMD} >${DISTNAME}.tar.xz

.include <bsd.port.mk>
