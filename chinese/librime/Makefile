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

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs \
		glog:${PORTSDIR}/devel/glog \
		kyotocabinet:${PORTSDIR}/databases/kyotocabinet \
		opencc:${PORTSDIR}/chinese/opencc \
		yaml-cpp:${PORTSDIR}/devel/yaml-cpp

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
	${MKDIR} ${DATADIR}/data
	${INSTALL_DATA} ${DATASRC}/*.kct ${DATASRC}/*.bin ${DATADIR}/data/

PROJECTHOST=	rimeime
DATA_VER=	0.16
WRKSRC=		${WRKDIR}/${PORTNAME}
DATASRC=	${WRKDIR}/tmp
DATADIR=	${PREFIX}/share/rime

.include <bsd.port.mk>
