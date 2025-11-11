PORTNAME=	radicle
DISTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://distfiles.pirateparty.in/ashish/:sources \
		LOCAL/ashish:sources
DISTFILES=	${DISTNAME}.tar.gz:sources

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Sovereign code forge built on Git
WWW=		https://radicle.xyz/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

GIT_HEAD=	5fea9ac05c7296dce3f8dec363b7442bec929c55

USES=			cargo
CARGO_INSTALL_PATH=	crates/radicle-cli crates/radicle-remote-helper \
			crates/radicle-node
CARGO_ENV=		GIT_HEAD=${GIT_HEAD} \
			RADICLE_VERSION=${DISTVERSION} \
			SOURCE_DATE_EPOCH=1758638030
PLIST_FILES=		bin/git-remote-rad \
			bin/rad \
			bin/radicle-node

DOCS_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
DOCS_PLIST_FILES=	share/man/man1/git-remote-rad.1.gz \
			share/man/man1/rad-id.1.gz \
			share/man/man1/rad-patch.1.gz \
			share/man/man1/rad.1.gz \
			share/man/man1/radicle-node.1.gz

# courtesy: https://reproducible-builds.org/docs/archives/
generate-tarball:
	git init --bare ${PORTNAME}
	git -C ${PORTNAME} remote add origin https://seed.radicle.xyz/z3gqcJUoA1n9HaHKufZs5FCSGazv5.git
	git -C ${PORTNAME} fetch --depth=1 origin ${GIT_HEAD}
	${RM} -rf ${DISTNAME}
	git -C ${PORTNAME} archive --format tar --prefix ${DISTNAME}/ \
		${GIT_HEAD} | ${TAR} xf -
	${FIND} ${DISTNAME} -print0 | \
	     ${XARGS} -0r ${TOUCH} -d '1970-01-01T00:00:00Z'
	${FIND} ${DISTNAME} -print0 | LC_ALL=C ${SORT} -z | \
		sudo ${TAR} --owner=0 --group=0 --numeric-owner --no-recursion \
		--null -T - -cf - ${DISTNAME} | \
		${GZIP_CMD} -9n >${DISTNAME}.tar.gz
	git -C ${PORTNAME} log -1 --pretty=%ct ${GIT_HEAD}
	${RM} -rf ${PORTNAME} ${DISTNAME}

post-build-DOCS-on:
	cd ${WRKSRC} && scripts/build-man-pages.sh . *.adoc

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
.for MANPAGE in ${DOCS_PLIST_FILES:T}
	${INSTALL_MAN} ${WRKSRC}/${MANPAGE:S/.gz//} ${STAGEDIR}${PREFIX}/share/man/man1
.endfor

.include <bsd.port.mk>
