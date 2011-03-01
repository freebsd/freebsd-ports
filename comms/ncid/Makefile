# New ports collection makefile for:   ncid
# Date created:        06 June 2005
# Whom:                David
#
# $FreeBSD$
#

PORTNAME=	ncid
PORTVERSION=	0.81
CATEGORIES=	comms
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Network based Caller ID package

USE_TK=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
MAN1=		ncid.1 ncid2ncid.1 ncidrotate.1 yac2ncid.1 ncidmodules.1 ncidtools.1 \
		cidalias.1 cidcall.1 cidupdate.1 ncid-initmodem.1 ncid-kpopup.1 ncid-mythtv.1 \
		ncid-page.1 ncid-samba.1 ncid-skel.1 ncid-speak.1 ncid-tivo.1 ncid-yac.1
MAN5=		ncid.conf.5 ncidmodules.conf.5 ncidd.alias.5 ncidrotate.conf.5 ncidd.blacklist.5 \
		ncidsip.conf.5 sip2ncid.conf.5 ncidd.conf.5 ncid2ncid.conf.5 yac2ncid.conf.5
MAN8=		ncidd.8 ncidsip.8 sip2ncid.8

USE_GMAKE=	yes
ALL_TARGET=	local
MAKE_ARGS=	WISH=${WISH} TCLSH=${TCLSH}
INSTALL_TARGET=	freebsd-install
SUB_FILES=	pkg-message

post-extract:
	@cd ${WRKSRC}/FreeBSD;for i in *.rc; do \
		x=`echo $$i | cut -f 1 -d .`; ${CP} $$i $$x; done

post-patch:
	@${GREP} -lr 'etc/ncid' ${WRKSRC}/|${XARGS} ${REINPLACE_CMD} -Ee\
		's,(/usr/local/etc/ncid|/etc/ncid),${ETCDIR},g'
	@${FIND} ${WRKSRC}/ -name Makefile|${XARGS} ${REINPLACE_CMD} -Ee\
		'/install:/s,install-(etc|logrotate),,'
	@${REINPLACE_CMD} -Ee '/mkdir.*(INIT|ROTATE|BIN|LOG|ETC)/d;\
		/CFLAGS.*=/s|=|+=|' ${WRKSRC}/Makefile
# Respect PREFIX/MANPREFIX/DATADIR
	@${REINPLACE_CMD} -e's|prefix.*= /usr/local|prefix=$${PREFIX}|g' \
		-e 's|$$(prefix)/bin|$${PREFIX}/bin|g' \
		-e 's|$$(prefix)/sbin|$${PREFIX}/sbin|g' \
		-e 's|$$(prefix)/share|$${PREFIX}/share|g' \
		-e 's|$$(SHARE)/man|$${MANPREFIX}/man/|g' \
		-e 's|$$(SHARE)/ncid|$${DATADIR}|g' ${WRKSRC}/Makefile

post-install:
	@${INSTALL} -d ${ETCDIR}/
	@cd ${WRKSRC};for i in server/*.alias scripts/*.conf;do\
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
