# Created by: Jarrod Sayers <jarrod@downtools.com.au>
# $FreeBSD$

PORTNAME=	shoutcast
PORTVERSION=	2.4.7.256
PORTREVISION=	2
CATEGORIES=	audio net
MASTER_SITES=	http://download.nullsoft.com/shoutcast/tools/ \
		http://people.freebsd.org/~sbruno/shoutcast/distfiles/
DISTNAME=	sc_serv2_bsd-latest

MAINTAINER=	sbruno@FreeBSD.org
COMMENT=	SHOUTcast Distributed Network Audio Server

RESTRICTED=	redistribution of software is not permitted
IA32_BINARY_PORT=	yes

USES=		dos2unix shebangfix
DOS2UNIX_REGEX=	.*\.(conf|css|html|js|txt|xml)
bash_CMD=	${SH}
SHEBANG_FILES=	setup.sh

USE_RC_SUBR=	shoutcast

CONFLICTS=	linux-shoutcast-[0-9]*
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	SERVERSETUP DOCS EXAMPLES
OPTIONS_DEFAULT=	SERVERSETUP
SERVERSETUP_DESC=	SHOUTcast Server Setup Tools
EXAMPLE_DESC=	SHOUTcast Server Example Configuration Files

DATADIR=		${WWWDIR}
SHOUTCASTLDIR=	/var/log/${PORTNAME}
SHOUTCASTDIR=	/var/run/${PORTNAME}

SHOUTCASTUSER=	${PORTNAME}
SHOUTCASTGROUP=	${PORTNAME}
USERS=		${SHOUTCASTUSER}
GROUPS=		${SHOUTCASTGROUP}

SUB_FILES=	pkg-message
SUB_LIST=	SHOUTCASTUSER=${SHOUTCASTUSER} SHOUTCASTDIR=${SHOUTCASTDIR}

PORTDATA=		*
PORTDOCS=		docs *.html *.pem *.txt
PORTEXAMPLES=	*.conf

PLIST_DIRS=		${ETCDIR} ${SHOUTCASTLDIR} ${SHOUTCASTDIR} \
		${SHOUTCASTDIR}/control ${SHOUTCASTDIR}/logs
PLIST_FILES=	sbin/sc_serv
.for ext in ban rip
PLIST_FILES+=	"@postunexec if [ ! -s ${SHOUTCASTDIR}/sc_serv.${ext} ];\
		then ${RM} ${SHOUTCASTDIR}/sc_serv.${ext}; fi"
.endfor

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000010
.if ${ARCH} == "i386"
RUN_DEPENDS+=	${LOCALBASE}/lib/compat/libstdc++.so.6:misc/compat9x
.else
RUN_DEPENDS+=	${LOCALBASE}/lib32/compat/libstdc++.so.6:misc/compat9x
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e '/sc_serv2 directory/d' \
		-e 's#=.*/\([^\.]*.log\)#=${SHOUTCASTLDIR}/\1#g' \
		-e 's#=control/#=${SHOUTCASTDIR}/#g' ${WRKSRC}/examples/sc_serv_*.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sc_serv ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${SHOUTCASTLDIR}
	@${MKDIR} ${STAGEDIR}${SHOUTCASTDIR}/control
	@${MKDIR} ${STAGEDIR}${SHOUTCASTDIR}/logs

do-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} "${PORTEXAMPLES}" \
		${STAGEDIR}${EXAMPLESDIR})

do-install-SERVERSETUP-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "setup setup.sh" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
