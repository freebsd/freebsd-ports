# Created by: gahr
# $FreeBSD$

PORTNAME=	netbeans
DISTVERSION=	10.0-vc5
CATEGORIES=	java devel
MASTER_SITES=	https://dist.apache.org/repos/dist/dev/incubator/netbeans/incubating-netbeans/incubating-${DISTVERSION}/
PKGNAMESUFFIX=	-devel
DISTNAME=	incubating-netbeans-${DISTVERSION}-bin

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Full-featured integrated environment for Java (unstable)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		shebangfix zip

USE_JAVA=	yes
JAVA_VERSION=	1.8+
NO_BUILD=	yes

SHEBANG_FILES=	extide/ant/bin/antRun.pl \
		extide/ant/bin/complete-ant-cmd.pl \
		extide/ant/bin/runant.pl \
		extide/ant/bin/runant.py

perl_OLD_CMD=	/usr/bin/perl
perl_CMD=	${LOCALBASE}/bin/perl
python_OLD_CMD=	/usr/bin/python
python_CMD=	${LOCALBASE}/bin/python2.7

WRKSRC=		${WRKDIR}/netbeans
PREFIXDIR=	${PREFIX}/netbeans-${PORTVERSION}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

DESKTOP_ENTRIES="NetBeans ${PORTVERSION}" \
		"NetBeans ${PORTVERSION} IDE" \
		${DATADIR}/nb/netbeans.png \
		${PORTNAME}-${PORTVERSION} \
		"Development;" \
		false

post-patch:
	@${REINPLACE_CMD} -e '57s|#||;57s|/path/to/jdk|${JAVA_HOME}|' \
	    ${WRKSRC}/etc/netbeans.conf
	@${FIND} ${WRKSRC} -name "*.orig" -delete

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIXDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}
	${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/bin/netbeans
	${LN} -sf ${DATADIR}/bin/netbeans ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${PORTVERSION}
 
	${FIND} ${STAGEDIR}${DATADIR} -type f -ipath "*/bin/*" | ${XARGS} ${CHMOD} ${BINMODE}

.include <bsd.port.mk>
