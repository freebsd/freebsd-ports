PORTNAME=	arttime
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
CATEGORIES=	deskutils

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Bring curated text/ascii art to artless terminals
WWW=		https://github.com/poetaman/arttime

LICENSE=	Arttime CFLAv1 GPLv3
LICENSE_COMB=	multi
LICENSE_NAME_Arttime=	Art for Personal Use
LICENSE_NAME_CFLAv1=	Collective Friendliness License Addendum version 1.0
LICENSE_FILE_Arttime=	${WRKSRC}/LICENSE_ART
LICENSE_FILE_CFLAv1=	${WRKSRC}/LICENSE_ADDENDUM_CFLA
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE_CODE
LICENSE_PERMS_Arttime=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell \
			auto-accept
LICENSE_PERMS_CFLAv1=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell \
			auto-accept

BUILD_DEPENDS=	zsh>=5.8:shells/zsh
RUN_DEPENDS=	${LOCALBASE}/share/terminfo/x/xterm-256color:misc/terminfo-db \
		notify-send:devel/libnotify \
		ogg123:audio/vorbis-tools \
		zsh>=5.8:shells/zsh

USE_GITHUB=	yes
GH_ACCOUNT=	poetaman

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
