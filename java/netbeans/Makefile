PORTNAME=	netbeans
DISTVERSION=	28
CATEGORIES=	java devel
MASTER_SITES=	APACHE/netbeans/netbeans/${DISTVERSION}/
DISTNAME=	netbeans-${DISTVERSION}-bin

MAINTAINER=	freethread.pe@gmail.com
COMMENT=	Modular, standards-based integrated development environment
WWW=		https://netbeans.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe java perl5 python:run shebangfix zip
CPE_VENDOR=	apache
JAVA_VERSION=	21 17 25

SHEBANG_FILES=	extide/ant/bin/antRun.pl \
		extide/ant/bin/complete-ant-cmd.pl \
		extide/ant/bin/runant.pl \
		extide/ant/bin/runant.py

DATADIR=	${PREFIX}/${PORTNAME}-${DISTVERSION}
DESKTOP_ENTRIES="Apache NetBeans ${DISTVERSION}" \
		"Apache NetBeans IDE ${DISTVERSION}" \
		${DATADIR}/nb/${PORTNAME}.png \
		${PORTNAME} \
		"Development;" \
		false
EXTRACT_BEFORE_ARGS=	-qo \
		-x '*.bat' -x '*.cmd' -x '*.dll' -x '*.dylib' -x '*.exe' \
		-x 'netbeans/ide/bin/nativeexecution/*64*' \
		-x 'netbeans/ide/bin/nativeexecution/*-x86*' \
		-x 'netbeans/ide/modules/lib/*' \
		-x 'netbeans/java/maven/lib/jansi-native*' \
		-x 'netbeans/platform/modules/lib/*' \
		-x 'netbeans/profiler/lib/deployed*'
NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -i '' -e '80s|#||;80s|/path/to/jdk|${JAVA_HOME}|' \
		${WRKSRC}/etc/${PORTNAME}.conf

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${RLN}  ${STAGEDIR}${PREFIX}/${PORTNAME}-${DISTVERSION}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${RLN}  ${STAGEDIR}${PREFIX}/${PORTNAME}-${DISTVERSION}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${DISTVERSION}

.include <bsd.port.mk>
