# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	librime
PORTVERSION=	0.9.7
CATEGORIES=	chinese textproc
MASTER_SITES=	GOOGLE_CODE
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} brise-${DATA_VER}.tar.gz

MAINTAINER=	lichray@gmail.com
COMMENT=	Rime Input Method Engine

LICENSE=	GPLv3

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libglog.so:${PORTSDIR}/devel/glog \
		libkyotocabinet.so:${PORTSDIR}/databases/kyotocabinet \
		libopencc.so:${PORTSDIR}/chinese/opencc \
		libyaml-cpp.so:${PORTSDIR}/devel/yaml-cpp

USES=		cmake pkgconfig gettext perl5
USE_PERL5=	build patch
USE_LDCONFIG=	yes
USE_XORG=	xproto
LDFLAGS+=	-lintl

PLIST_SUB=	VER=${PORTVERSION}

post-patch:     .SILENT
	${FIND} ${WRKSRC} \( -name '*.cc' -or -name '*.h' \) \
		-exec ${PERL} -i -pe '$$. == 1 && s/^\xef\xbb\xbf//;' '{}' \;

post-build:
	@echo "building rime data."
	@${MKDIR} ${DATASRC}
	@(cd ${WRKDIR}/brise; ${CP} \
	default.yaml essay.kct supplement/*.yaml preset/*.yaml ${DATASRC})
	${WRKSRC}/bin/rime_deployer --build ${DATASRC}

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/data
	${INSTALL_DATA} ${DATASRC}/*.kct ${DATASRC}/*.bin ${STAGEDIR}${DATADIR}/data/

PROJECTHOST=	rimeime
DATA_VER=	0.16
WRKSRC=		${WRKDIR}/${PORTNAME}
DATASRC=	${WRKDIR}/tmp
DATADIR=	${PREFIX}/share/rime

.include <bsd.port.mk>
