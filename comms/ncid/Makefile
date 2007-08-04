# New ports collection makefile for:   ncid
# Date created:        06 June 2005
# Whom:                David
#
# $FreeBSD$
#

PORTNAME=	ncid
PORTVERSION=	0.68
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network based Caller ID package

USE_TK=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
MAN1=		ncid.1 ncidscripts.1 ncidtools.1 yac2ncid.1
MAN5=		ncid.conf.5 ncidd.alias.5 ncidd.conf.5 ncidscript.conf.5 yac2ncid.conf.5
MAN8=		ncidd.8 ncidsip.8

USE_GMAKE=	yes
ALL_TARGET=	local
MAKE_ARGS=	WISH=${WISH} TCLSH=${TCLSH}
INSTALL_TARGET=	install-freebsd
SUB_FILES=	pkg-message

post-patch:
	@${GREP} -lr 'etc/ncid' ${WRKSRC}/|${XARGS} ${REINPLACE_CMD} -Ee\
		's,(/usr/local/etc/ncid|/etc/ncid),${ETCDIR},g'
	@${FIND} ${WRKSRC}/ -name Makefile|${XARGS} ${REINPLACE_CMD} -Ee\
		'/install:/s,install-(etc|logrotate),,'
	@${REINPLACE_CMD} -e 's|source|.|;s|bash|sh|;/test/s|==|=|;/local/s|-i||'\
		${WRKSRC}/tools/yac2ncid.sh
	@${REINPLACE_CMD} -Ee '/mkdir.*(INIT|ROTATE|BIN|LOG|ETC)/d;\
		/CFLAGS.*=/s|=|+=|;s|-O||' ${WRKSRC}/Makefile

post-install:
	@${INSTALL} -d ${ETCDIR}/
	@cd ${WRKSRC};for i in *.alias *.conf scripts/*.conf tools/*.conf;do\
		ib=`basename $$i`;\
		${INSTALL_DATA} $$i ${ETCDIR}/$$ib.dist;\
		${CP} -n ${ETCDIR}/$$ib.dist ${ETCDIR}/$$ib;\
		${ECHO_CMD} "@unexec cd %D/${ETCDIR_REL}/;! cmp -s $$ib $$ib.dist||\
			${RM} -f $$ib">>${TMPPLIST};\
		${ECHO_CMD} "${ETCDIR_REL}/$$ib.dist">>${TMPPLIST};\
		${ECHO_CMD} "@exec ${CP} -n %D/%F %D/${ETCDIR_REL}/$$ib">>${TMPPLIST};\
	done
	@${ECHO_CMD} "@unexec ${RMDIR} %D/${ETCDIR_REL} 2>/dev/null || true">>${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
