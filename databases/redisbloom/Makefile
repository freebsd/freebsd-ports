PORTNAME=	redisbloom
DISTVERSIONPREFIX=	v
DISTVERSION=	8.8.0
CATEGORIES=	databases

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Probabilistic Data Structures for Redis
WWW=		https://github.com/RedisBloom/RedisBloom

LICENSE=	AGPLv3 RSALv2 SSPLv1
LICENSE_COMB=	dual
LICENSE_NAME_RSALv2=	Redis Source Available License v2
LICENSE_NAME_SSPLv1=	Server Side Public License v1
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS_RSALv2=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	RedisBloom
GH_PROJECT=	RedisBloom
GH_TUPLE=	RedisBloom:t-digest-c:5b89d70:t_digest_c/deps/t-digest-c \
		RedisLabsModules:readies:f31347b:readies/deps/readies \
		RedisLabsModules:RedisModulesSDK:3b2f684:RedisModulesSDK/deps/RedisModulesSDK \
		google:benchmark:8982e1e:benchmark/deps/t-digest-c/tests/vendor/google/benchmark

CFLAGS+=	-fPIC -fblocks \
		-D_GNU_SOURCE -DREDIS_MODULE_TARGET -DREDISMODULE_SDK_RLEC \
		-I${WRKSRC}/src -I${WRKSRC}/deps/RedisModulesSDK -I${WRKSRC}/deps \
		-I${WRKSRC}/deps/murmur2 -I${WRKSRC}/deps/t-digest-c/src

PLIST_FILES=	lib/redisbloom.so

MODULE_SRCS=	deps/bloom/bloom.c deps/murmur2/MurmurHash2.c deps/rmutil/util.c \
		src/cmd_info/cf_info.c src/cmd_info/bf_info.c src/cmd_info/cms_info.c \
		src/cmd_info/tdigest_info.c src/cmd_info/topk_info.c \
		src/rebloom.c src/sb.c src/cf.c src/rm_topk.c src/rm_tdigest.c \
		src/topk.c src/rm_cms.c src/cms.c src/config.c \
		deps/t-digest-c/src/tdigest.c

do-build:
	@cd ${WRKSRC} && for s in ${MODULE_SRCS}; do \
		echo "  CC $$s"; ${CC} ${CFLAGS} -c $$s -o $${s%.c}.o || exit 1; \
	done
	@cd ${WRKSRC} && ${CC} -shared ${LDFLAGS} -o redisbloom.so ${MODULE_SRCS:.c=.o}

do-install:
	${INSTALL_LIB} ${WRKSRC}/redisbloom.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
