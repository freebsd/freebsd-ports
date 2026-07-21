PORTNAME=	bun-linux
DISTVERSION=	1.3.14
CATEGORIES=	lang
MASTER_SITES=	https://github.com/oven-sh/bun/releases/download/bun-v${DISTVERSION}/:amd64 \
		https://github.com/oven-sh/bun/releases/download/bun-v${DISTVERSION}/:aarch64
DISTFILES=	bun-linux-x64-baseline.zip:amd64 \
		bun-linux-aarch64.zip:aarch64
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Linux version of Bun JavaScript runtime and package manager
WWW=		https://bun.com/ \
		https://github.com/oven-sh/bun

LICENSE=	LGPL20

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	is a Linux binary with a limited platform support

USES=		linux:rl9 zip
USE_LINUX=	base

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
STRIP=		# elftoolchain strip fails on these Linux binaries

CONFLICTS_INSTALL=	bun

PLIST_FILES=	bin/bun \
		libexec/bun

find-new-version:
	@TAB=$$(printf '\t'); \
	new_ver=$$(fetch -q -o - https://api.github.com/repos/oven-sh/bun/releases/latest 2>/dev/null | \
		${GREP} '"tag_name":' | head -1 | ${SED} 's/.*"bun-v\([^"]*\)".*/\1/'); \
	current_ver=$$(make -V DISTVERSION); \
	if [ "$$new_ver" != "$$current_ver" ] && [ -n "$$new_ver" ]; then \
		${SED} -i '' "s/^DISTVERSION=.*/DISTVERSION=$${TAB}$$new_ver/" ${.CURDIR}/Makefile; \
		echo "=> New version available: $$current_ver -> $$new_ver"; \
	else \
		echo "=> No new version available (current: $$current_ver)"; \
	fi

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
BUN_DISTDIR=	bun-linux-aarch64
.else
BUN_DISTDIR=	bun-linux-x64-baseline
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BUN_DISTDIR}/bun ${STAGEDIR}${PREFIX}/libexec/bun
	( \
		${ECHO}	"#!/bin/sh"; \
		${ECHO}	"if [ ! -d /compat/linux/proc ]; then"; \
		${ECHO}	"  echo 'Error: /compat/linux/proc is not mounted. Please run \"sudo mount -t linprocfs linprocfs /compat/linux/proc\" to mount it.'"; \
		${ECHO}	"  exit 1"; \
		${ECHO}	"fi"; \
		${ECHO}	"exec ${PREFIX}/libexec/bun \"\$$@\"" \
	) > ${WRKSRC}/bun-wrapper.sh
	${INSTALL_SCRIPT} ${WRKSRC}/bun-wrapper.sh ${STAGEDIR}${PREFIX}/bin/bun

.include <bsd.port.post.mk>
