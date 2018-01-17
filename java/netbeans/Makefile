# Created by: olgeni@FreeBSD.org
# $FreeBSD$

PORTNAME=	netbeans
PORTVERSION=	8.2
CATEGORIES=	java devel
MASTER_SITES=	http://download.netbeans.org/netbeans/${PORTVERSION}/final/zip/ \
		http://dlc.sun.com.edgesuite.net/netbeans/${PORTVERSION}/final/zip/
DISTNAME=	netbeans-${PORTVERSION}-201609300101

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Modular, standards-based integrated development environment (unstable version)

LICENSE=	CDDL GPLv2
LICENSE_COMB=	dual

USES=		shebangfix zip
SHEBANG_FILES=	extide/ant/bin/antRun.pl \
		extide/ant/bin/complete-ant-cmd.pl \
		extide/ant/bin/runant.pl \
		extide/ant/bin/runant.py
perl_OLD_CMD=	/usr/bin/perl
perl_CMD=	${LOCALBASE}/bin/perl
python_OLD_CMD=	/usr/bin/python
python_CMD=	${LOCALBASE}/bin/python2.7

USE_JAVA=	yes
JAVA_VERSION=	1.8
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/netbeans
DATADIR=	${PREFIX}/${PORTNAME}-${PORTVERSION}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

DESKTOP_ENTRIES="NetBeans" \
		"NetBeans IDE" \
		${DATADIR}/nb/netbeans.png \
		${PORTNAME}-${PORTVERSION} \
		"Development;" \
		false

post-patch:
	@${REINPLACE_CMD} -i "" -e '57s|#||;57s|/path/to/jdk|${JAVA_HOME}|' \
	    ${WRKSRC}/etc/netbeans.conf
	@${FIND} ${WRKSRC} -name "*.orig" -delete

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}
	${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/bin/netbeans
	${LN} -sf ${DATADIR}/bin/netbeans ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${PORTVERSION}

	${FIND} ${STAGEDIR}${DATADIR} -type f -ipath "*/bin/*" | ${XARGS} ${CHMOD} ${BINMODE}

.include <bsd.port.mk>
