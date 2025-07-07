PORTNAME=	netbeans
DISTVERSION=	17
CATEGORIES=	java devel
MASTER_SITES=	APACHE/netbeans/netbeans/${PORTVERSION}/
DISTNAME=	netbeans-${DISTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular, standards-based integrated development environment
WWW=		https://netbeans.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe java shebangfix zip
CPE_VENDOR=	apache
JAVA_VERSION=	11 17

NO_BUILD=	yes

SHEBANG_FILES=	extide/ant/bin/antRun.pl \
		extide/ant/bin/complete-ant-cmd.pl \
		extide/ant/bin/runant.pl \
		extide/ant/bin/runant.py

perl_OLD_CMD=	/usr/bin/perl
perl_CMD=	${LOCALBASE}/bin/perl
python_OLD_CMD=	/usr/bin/python
python_CMD=	${LOCALBASE}/bin/python${PYTHON_DEFAULT}

WRKSRC=		${WRKDIR}/netbeans
DATADIR=	${PREFIX}/${PORTNAME}-${PORTVERSION}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

DESKTOP_ENTRIES="Apache NetBeans" \
		"Apache NetBeans IDE (incubating)" \
		${DATADIR}/nb/netbeans.png \
		${PORTNAME} \
		"Development;" \
		false

post-patch:
	@${REINPLACE_CMD} -i '' -e '77s|#||;77s|/path/to/jdk|${JAVA_HOME}|' \
	    ${WRKSRC}/etc/netbeans.conf
	@${FIND} ${WRKSRC} -name "*.orig" -delete

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}
	cd ${STAGEDIR}${PREFIX} && ${LN} -sf ../${PORTNAME}-${PORTVERSION}/bin/netbeans bin/${PORTNAME}
	cd ${STAGEDIR}${PREFIX} && ${LN} -sf ../${PORTNAME}-${PORTVERSION}/bin/netbeans bin/${PORTNAME}-${PORTVERSION}
	${RM} -rf ${STAGEDIR}${DATADIR}/profiler/lib/deployed/jdk16/linux-arm*

.include <bsd.port.mk>
