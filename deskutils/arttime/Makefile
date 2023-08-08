PORTNAME=	arttime
PORTVERSION=	2.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Bring curated text/ascii art to artless terminals
WWW=		https://github.com/poetaman/arttime

LICENSE=	GPLv3

BUILD_DEPENDS=	zsh>=5.8:shells/zsh
RUN_DEPENDS=	${LOCALBASE}/share/terminfo/x/xterm-256color:misc/terminfo-db \
		notify-send:devel/libnotify \
		ogg123:audio/vorbis-tools \
		zsh>=5.8:shells/zsh

USE_GITHUB=	yes
GH_ACCOUNT=	poetaman
GH_TAGNAME=	6716e6b

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=		FZF
OPTIONS_DEFAULT=	FZF

FZF_DESC=	Use FZF to select ASCII art

FZF_RUN_DEPENDS=	fzf:textproc/fzf

do-install:
	${SETENV} ${MAKE_ENV} DESTDIR=${STAGEDIR} ${WRKSRC}/install.sh \
		--prefix ${STAGEDIR}${PREFIX} --noupdaterc

.include <bsd.port.mk>
