# Created by: David
# $FreeBSD$

PORTNAME=	ncid
PORTVERSION=	1.11
CATEGORIES=	comms
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Network based Caller ID package

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/doc/GPL.md

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libpcre.so:devel/pcre
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c11 gmake perl5 tk shebangfix
USE_GCC=	yes

SHEBANG_FILES=	client/ncid.sh \
		desktop/xml \
		doc/mk* \
		extensions/*.sh \
		gateway/*.pl gateway/*.sh \
		logrotate/*.sh \
		man/mk-pdf \
		modules/*.sh \
		setup/*.sh \
		tools/*.pl tools/*.sh

ALL_TARGET=	local
MAKE_ARGS=	WISH=${WISH} TCLSH=${TCLSH} \
		CC=${CC} HOSTCC=${CC} AR=${AR}
INSTALL_TARGET=	freebsd-install

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS LOGROTATE
OPTIONS_SUB=	yes

LOGROTATE_DESC=	Install logrotate scripts

LOGROTATE_RUN_DEPENDS=	logrotate:sysutils/logrotate

WRKSRC=	${WRKDIR}/${PORTNAME}

post-extract:
	@cd ${WRKSRC}/FreeBSD;for i in *.rc; do \
		x=`echo $$i | cut -f 1 -d .`; ${CP} $$i $$x; done

.include <bsd.port.pre.mk>

post-patch:
	@${GREP} -lr 'etc/ncid' ${WRKSRC}/ | ${XARGS} ${REINPLACE_CMD} -Ee \
		's,(/usr/local/etc/ncid | /etc/ncid),${ETCDIR},g'
	@${FIND} ${WRKSRC}/ -name Makefile | ${XARGS} ${REINPLACE_CMD} -Ee \
		'/install:/s,install-(etc|logrotate),,'
	@${REINPLACE_CMD} -Ee '/mkdir.*(INIT|ROTATE|BIN|LOG|ETC)/d ;\
		/CFLAGS.*=/s|=|+=|' ${WRKSRC}/Makefile
# Respect PREFIX/MANPREFIX/DATADIR
	@${REINPLACE_CMD} -e 's|prefix.*= /usr/local|prefix=$${PREFIX}|g' \
		-e 's|$$(prefix)/bin|$${PREFIX}/bin|g' \
		-e 's|$$(prefix)/sbin|$${PREFIX}/sbin|g' \
		-e 's|$$(prefix)/share|$${PREFIX}/share|g' \
		-e 's|$$(SHARE)/man|$${MANPREFIX}/man/|g' \
		-e 's|$$(SHARE)/ncid|$${DATADIR}|g' ${WRKSRC}/Makefile
.if ${CHOSEN_COMPILER_TYPE} == gcc
	@${REINPLACE_CMD} -e 's|-Wno-stringop-truncation||g' \
		${WRKSRC}/Makefile ${WRKSRC}/server/Makefile
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/server/ncidd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/gateway/ncid2ncid ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gateway/sip2ncid ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/client/ncid ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/client/ncid.conf ${STAGEDIR}${ETCDIR}/ncid.conf.sample
	${INSTALL_DATA} ${WRKSRC}/gateway/ncid2ncid.conf ${STAGEDIR}${ETCDIR}/ncid2ncid.conf.sample
	${INSTALL_DATA} ${WRKSRC}/gateway/sip2ncid.conf ${STAGEDIR}${ETCDIR}/sip2ncid.conf.sample
.for d in ncidd.alias ncidd.conf ncidd.blacklist ncidd.whitelist
	${INSTALL_DATA} ${WRKSRC}/server/${d} ${STAGEDIR}${ETCDIR}/${d}.sample
.endfor
.for e in hangup-calls hangup-fakenum hangup-fcc hangup-nohangup \
hangup-closed-skel hangup-combo-skel hangup-message-skel hangup-skel
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/ncid/extensions
	${INSTALL_SCRIPT} ${WRKSRC}/extensions/${e} ${STAGEDIR}${PREFIX}/share/ncid/extensions
.endfor
# ncid2ncid and sip2ncid are installed and stripped before this loop with ${INSTALL_PROGRAM}
.for f in email2ncid obi2ncid rn2ncid wc2ncid xdmf2ncid yac2ncid
	${INSTALL_SCRIPT} ${WRKSRC}/gateway/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/gateway/${f}.conf ${STAGEDIR}${ETCDIR}/${f}.conf.sample
.endfor
	${INSTALL_DATA} ${WRKSRC}/client/ncid.gif ${STAGEDIR}${PREFIX}/share/pixmaps/ncid
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/ncid/modules
.for g in ncid-alert ncid-initmodem ncid-kpopup ncid-mysql ncid-mythtv ncid-notify ncid-page \
ncid-samba ncid-skel ncid-speak ncid-wakeup ncid-yac
	${INSTALL_SCRIPT} ${WRKSRC}/modules/${g} ${STAGEDIR}${PREFIX}/share/ncid/modules
.endfor
	${INSTALL_DATA} ${WRKSRC}/server/ncidd.alias ${STAGEDIR}${ETCDIR}/ncidd.alias.sample
.for h in cidcall cidalias cidupdate wct ncidutil
	${INSTALL_SCRIPT} ${WRKSRC}/tools/${h} ${STAGEDIR}${PREFIX}/bin
.endfor
.for i in ncid-initmodem ncid-mysql ncid-mythtv ncid-notify ncid-page ncid-samba ncid-speak ncid-yac \
ncid2ncid ncidd obi2ncid rn2ncid sip2ncid wc2ncid xdmf2ncid yac2ncid
	${INSTALL_DATA} ${WRKSRC}/FreeBSD/${i} ${STAGEDIR}${PREFIX}/etc/rc.d
.endfor
.for j in CallingDeposit.rmd CannotBeCompleted.rmd DisconnectedNotInService.rmd NotInService.rmd
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/ncid/recordings
	${INSTALL_DATA} ${WRKSRC}/recordings/${j} ${STAGEDIR}${PREFIX}/share/ncid/recordings
.endfor
.for k in ncid-email2ncid-setup ncid-mysql-setup ncid-setup
	${INSTALL_SCRIPT} ${WRKSRC}/setup/${k} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/*.5 ${STAGEDIR}${MAN5PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/man/*.7 ${STAGEDIR}${MAN7PREFIX}/man/man7
	${INSTALL_MAN} ${WRKSRC}/man/*.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/recordings
	${INSTALL_DATA} ${WRKSRC}/doc/*.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FreeBSD/README-FreeBSD ${STAGEDIR}${DOCSDIR}
.for l in README-recordings CallingDeposit.pvf CannotBeCompleted.pvf DisconnectedNotInService.pvf NotInService.pvf
	${INSTALL_DATA} ${WRKSRC}/recordings/${l} ${STAGEDIR}${DOCSDIR}/recordings
.endfor

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/bin/cidupdate

post-install-LOGROTATE-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/ncid/sys
	${INSTALL_SCRIPT} ${WRKSRC}/tools/ncid-yearlog ${STAGEDIR}${PREFIX}/share/ncid/sys
	${INSTALL_SCRIPT} ${WRKSRC}/logrotate/ncidrotate ${STAGEDIR}${PREFIX}/share/ncid/sys
	${INSTALL_DATA} ${WRKSRC}/logrotate/ncidrotate.conf ${STAGEDIR}${ETCDIR}/ncidrotate.conf.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/logrotate.d
	${INSTALL_DATA} ${WRKSRC}/logrotate/ncid ${STAGEDIR}${PREFIX}/etc/logrotate.d
	${INSTALL_MAN} ${WRKSRC}/logrotate/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/logrotate/*.5 ${STAGEDIR}${MAN5PREFIX}/man/man5

.include <bsd.port.post.mk>
