PORTNAME=	soju
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	irc

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	IRC bouncer
WWW=		https://soju.im

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules,no_targets sqlite:3
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.30.0:sys

OPTIONS_DEFAULT=	DOCS
OPTIONS_DEFINE=		DOCS

USERS=			soju
GROUPS=			soju
SUB_LIST=		USER=${USERS}
USE_RC_SUBR=		${PORTNAME}
CGO_LDFLAGS+=		-lsqlite3
GO_MODULE=		codeberg.org/emersion/soju
CONTRIBS=		./contrib/znc-import ./contrib/migrate-db \
			./contrib/migrate-logs
MAKE_ENV+=		${GO_ENV} GOFLAGS="${GOFLAGS} -tags=libsqlite3,pam" \
			MANDIR=share/man \
			PREFIX=${PREFIX} \
			RUNDIR=/var/run \
			SYSCONFDIR=${ETCDIR}/..
PLIST_FILES=		${CONTRIBS:T:C/^/bin\/soju-/g} \
			${DOCSDIR_REL}/getting-started.md \
			"@sample ${ETCDIR_REL}/config.sample" \
			"@dir(${USERS},${GROUPS},0711) /var/db/soju" \
			bin/soju \
			bin/sojuctl \
			bin/sojudb
DOCS_BUILD_DEPENDS=	scdoc:textproc/scdoc
DOCS_PLIST_FILES=	share/man/man1/soju.1.gz \
			share/man/man1/sojuctl.1.gz

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

post-patch:
	@${REINPLACE_CMD} -r -e 's,/var/lib/soju,/var/db/soju,g' \
		${WRKSRC}/config.in
	@${REINPLACE_CMD} -r -e 's,[$$]\(([^)]+)\),$${\1},g' \
		-e 's,(/cmd/sojuctl)$$,\1 ${CONTRIBS},' \
		-e '/^config_path/s,=.*$$,= ${ETCDIR}/config,' \
		-e '/^RUNDIR/s,=.*$$,= /var/run,' \
		-e '/^commands/s,$$, ${CONTRIBS:T},' \
		-e '/^sojudb/s,^,${CONTRIBS:T} ,' \
		-e '/^\.PHONY/s,$$, ${CONTRIBS:T},' \
		-e '/^sharedstatedir/s,/var/lib,/var/db,' ${WRKSRC}/Makefile

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's,[$$]{man_pages},,' -e '/man1$$/d' ${WRKSRC}/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/getting-started.md ${STAGEDIR}${DOCSDIR}
.for EXE in ${CONTRIBS:T}
	${MV} ${STAGEDIR}${PREFIX}/bin/${EXE} ${STAGEDIR}${PREFIX}/bin/soju-${EXE}
.endfor
	${MV} ${STAGEDIR}${ETCDIR}/config ${STAGEDIR}${ETCDIR}/config.sample
	${FIND} ${STAGEDIR}${PREFIX}/bin -type f -exec ${STRIP_CMD} {} \;

.include <bsd.port.mk>
