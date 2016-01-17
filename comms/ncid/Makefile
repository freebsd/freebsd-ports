# Created by: David
# $FreeBSD$

PORTNAME=	ncid
PORTVERSION=	1.3
CATEGORIES=	comms
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	cpm@fbsd.es
COMMENT=	Network based Caller ID package

LICENSE=	GPLv3

USES=		gmake perl5 tk
ALL_TARGET=	local
MAKE_ARGS=	WISH=${WISH} TCLSH=${TCLSH}
INSTALL_TARGET=	freebsd-install
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

WRKSRC=	${WRKDIR}/${PORTNAME}

PORTDOCS=	Alias.md CHANGES CONTRIBUTORS.md Clients.md Devices.md FAQ.md GPL.md \
		Gateways.md GettingStarted.md Hangup.md INSTALL-Cygwin.md INSTALL-Fedora.md \
		INSTALL-FreeBSD.md INSTALL-Mac.md INSTALL-Raspbian.md INSTALL-Redhat.md \
		INSTALL-TiVo.md INSTALL-Ubuntu.md INSTALL-Win.md INSTALL.md InstallIndex.md \
		Makefile Modems.md Modules.md NCID-API.md NCID-SDK.md Obtain.md README.docdir \
		ReleaseNotes.md TODO.md Tools.md Use.md UserManualIndex.md Verbose.md mk-epub \
		ncid-1.jpg ncid-cover.jpg

post-extract:
	@cd ${WRKSRC}/FreeBSD;for i in *.rc; do \
		x=`echo $$i | cut -f 1 -d .`; ${CP} $$i $$x; done

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

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/server/ncidd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/gateway/sip2ncid ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/client/ncid ${STAGEDIR}${PREFIX}/bin
.for f in ncid2ncid rn2ncid yac2ncid wc2ncid
	${INSTALL_DATA} ${WRKSRC}/gateway/${f} ${STAGEDIR}${PREFIX}/bin
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ncid2ncid
.endfor
	${INSTALL_DATA} ${WRKSRC}/client/ncid.gif ${STAGEDIR}${PREFIX}/share/pixmaps/ncid
.for g in ncid-page ncid-samba ncid-speak ncid-mythtv ncid-kpopup ncid-skel \
ncid-alert ncid-yac ncid-initmodem ncid-notify ncid-wakeup
	${INSTALL_DATA}	${WRKSRC}/modules/${g} ${STAGEDIR}${PREFIX}/share/ncid
.endfor
	${INSTALL_DATA} ${WRKSRC}/server/ncidd.alias ${STAGEDIR}${ETCDIR}
.for h in cidcall cidalias cidupdate wct ncidutil
	${INSTALL_DATA} ${WRKSRC}/tools/${h} ${STAGEDIR}${PREFIX}/bin
.endfor
.for i in ncidd ncid2ncid rn2ncid sip2ncid wc2ncid yac2ncid ncid-mythtv ncid-notify \
ncid-page ncid-samba ncid-speak ncid-yac ncid-initmodem
	${INSTALL_DATA} ${WRKSRC}/FreeBSD/${i} ${STAGEDIR}${PREFIX}/etc/rc.d
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/*.5 ${STAGEDIR}${MAN5PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/man/*.7 ${STAGEDIR}${MAN7PREFIX}/man/man7
	${INSTALL_MAN} ${WRKSRC}/man/*.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for j in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${j} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
