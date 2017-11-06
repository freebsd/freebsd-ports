# Created by: Serge Gagnon <serge.gagnon@b2b2c.ca>
# $FreeBSD$

PORTNAME=	plan9port
PORTVERSION=	20170723
CATEGORIES=	devel plan9

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of many Plan 9 programs to Unix-like operating systems

LICENSE=	LUCENT
LICENSE_NAME=	Lucent Public License Version 1.02
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GH_ACCOUNT=	9fans
GH_TAGNAME=	4a8c0c7
USE_GITHUB=	yes

DIST_SUBDIR=	${PORTNAME}

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

BROKEN_sparc64=	does not install: cleanname not found

OPTIONS_DEFINE=	SRC
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes

SRC_DESC=	Install sources

USES=		perl5 shebangfix tar:tgz
USE_XORG=	x11 xt xi xaw xext
USE_PERL5=	build

SHEBANG_LANG=	rc
rc_OLD_CMD=	/bin/rc /usr/local/plan9/bin/rc
rc_CMD=		${PLAN9}/bin/rc
# /usr/bin/perl
SHEBANG_FILES=	unix/man/fixurls
# /bin/rc
SHEBANG_FILES+=	acid/transcript \
		acid/window \
		mac/9term.app/Contents/MacOS/9term \
		mac/Plumb.app/Contents/MacOS/plumb \
		src/cmd/9660/mk9660.rc \
		src/cmd/acme/mail/mkbox \
		src/cmd/dict/egfix \
		src/cmd/dict/egfix2 \
		src/cmd/dict/gefix \
		src/cmd/dict/getneeds \
		src/cmd/lp/lpsend.rc \
		src/cmd/map/map.rc \
		src/cmd/map/mapdemo.rc \
		src/cmd/postscript/hardcopy/hardcopy.rc \
		src/cmd/postscript/psencoding/psencoding.rc \
		src/cmd/spell/spell.rc \
		src/cmd/upas/filterkit/pipefrom.sample \
		src/cmd/upas/filterkit/pipeto.sample-hold \
		src/cmd/upas/filterkit/pipeto.sample \
		tmac/sendcover \
		troff/font/devutf/mkMAP
# /usr/local/plan9/bin/rc
SHEBANG_FILES+=	bin/codereview \
		bin/quote1 \
		bin/quote2 \
		bin/ssam \
		bin/upas/isspam \
		bin/upas/msgcat \
		bin/upas/spam \
		bin/upas/spambox \
		bin/upas/unspam \
		bin/upas/unspambox \
		lp/bin/lpsend.rc \
		lp/bin/UNLOCK \
		lp/daemon/generic \
		lp/daemon/gsdev \
		lp/daemon/psdev \
		lp/kill/generic \
		lp/process/dvipost \
		lp/process/g3post \
		lp/process/generic \
		lp/process/gifpost \
		lp/process/hpost \
		lp/process/jpgpost \
		lp/process/noproc \
		lp/process/p9bitpost \
		lp/process/pdfgs \
		lp/process/pdfpost \
		lp/process/post \
		lp/process/ppost \
		lp/process/psextract \
		lp/process/tr2post \
		lp/sched/FIFO \
		lp/spooler/generic \
		lp/spooler/lpdspool \
		lp/spooler/nospool \
		lp/stat/generic \
		lp/stat/lpd \
		mail/lib/validateattachment \
		man/secindex \
		src/cmd/fossil/conf.rc \
		src/cmd/lp/lp.rc \
		src/cmd/netfiles/netfileget \
		src/cmd/netfiles/netfileput \
		src/cmd/netfiles/netfilestat \
		src/cmd/postscript/printfont/printfont.rc \
		src/cmd/upas/misc/mail.rc \
		src/cmd/upas/misc/qmail \
		src/cmd/upas/misc/remotemail \
		src/cmd/venti/srv/conf.rc

WRKSRC=		${WRKDIR}/plan9
PLIST=		${WRKDIR}/.PLIST
SUB_FILES=	pkg-message
REINPLACE_ARGS=	-i ""		# necessary since installs via recursive copy

PLAN9=		${PREFIX}/plan9

EMPTY_DIRS=	plan9/mail/queue \
		plan9/log \
		plan9/bin/lpbin

post-extract:
	${MV} ${WRKDIR}/plan9port-${GH_TAGNAME} ${WRKDIR}/plan9

post-patch:
	@${FIND} ${WRKSRC}/man -type f -regex ".*\.[0-9?]$\" \
		| ${XARGS} ${REINPLACE_CMD} -e 's|\\\*9|${PLAN9}|'
	@${REINPLACE_CMD} -e 's|X11=/usr/X11R6|X11=${LOCALBASE}|' \
		${WRKSRC}/bin/9l ${WRKSRC}/src/cmd/devdraw/mkwsysrules.sh
	@${REINPLACE_CMD} -e 's|\[5-9\]\.||' ${WRKSRC}/bin/9l
	@${REINPLACE_CMD} -e 's|/lib/font/bit|${PLAN9}/font|' \
		${WRKSRC}/src/cmd/acme/acme.c
	@${SED} -e 's|util\.h|lib&|' ${WRKSRC}/src/cmd/9term/OpenBSD.c \
		> ${WRKSRC}/src/cmd/9term/${OPSYS}.c
	@${REINPLACE_CMD} -e 's|, swizz(void)|&, swizz8(void)|' \
		${WRKSRC}/src/cmd/xd.c
	@${REINPLACE_CMD} -e '/^cd $$PLAN9/d' ${WRKSRC}/lib/moveplan9.sh
	@${REINPLACE_CMD} -e 's|^#!/bin/bash$$|#!/bin/sh|' ${WRKSRC}/bin/macedit
	@${REINPLACE_CMD} -e 's|#!/bin/rc|#!${PLAN9}/bin/rc|' \
		${WRKSRC}/src/cmd/upas/ml/mlmgr.c \
		${WRKSRC}/src/cmd/tcs/font/mkfile
	@${REINPLACE_CMD} -e '/<sys\/termios.h>/d' \
		${WRKSRC}/src/lib9/readcons.c \
		${WRKSRC}/src/cmd/9term/bsdpty.c
	@${REINPLACE_CMD} -e 's|<sys/termios.h>|<termios.h>|' \
		${WRKSRC}/src/cmd/draw/mc.c
	@${REINPLACE_CMD} -e 's|ulong|u64int|' ${WRKSRC}/src/libmach/FreeBSD.c
	@${REINPLACE_CMD} -e \
		'/[Rr]enaming hard-coded.*paths\./!s|/usr/local/|${PREFIX}/|' \
		${WRKSRC}/INSTALL
	@${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|g' \
		${WRKSRC}/bin/codereview \
		${WRKSRC}/bin/macedit \
		${WRKSRC}/lib/moveplan9.sh \
		${WRKSRC}/man/lookman.index \
		${WRKSRC}/plumb/basic \
		${WRKSRC}/src/cmd/9pfuse/errstr.c \
		${WRKSRC}/src/cmd/devdraw/mkwsysrules.sh \
		${WRKSRC}/src/cmd/fossil/mkfile \
		${WRKSRC}/src/cmd/lp/lp.rc \
		${WRKSRC}/src/cmd/postscript/printfont/printfont.rc \
		${WRKSRC}/src/cmd/sam/sam.c \
		${WRKSRC}/src/cmd/upas/nfs/imap.c \
		${WRKSRC}/src/cmd/venti/srv/mkfile \
		${WRKSRC}/src/lib9/_p9translate.c \
		${WRKSRC}/src/lib9/get9root.c \
		${WRKSRC}/src/libregexp/mkfile

do-build:
	@cd ${WRKSRC} && { \
		export PLAN9_TARGET="${PLAN9}" CC9="${CC}"; \
		if [ ! -t 1 ]; then \
			export winid=1; \
		fi; \
		./INSTALL; \
	}

post-build:
	@${FIND} ${WRKSRC} -name .cvsignore -o -name .gitignore -delete
	@${RM} ${WRKSRC}/configure ${WRKSRC}/config ${WRKSRC}/install.log \
		${WRKSRC}/install.sum
	@( cd ${WRKDIR} ; \
	  ${FIND} plan9 -type f; \
	  ${ECHO_CMD} "@dir(,,1777) plan9/news"; \
	  for D in ${EMPTY_DIRS}; do \
	    ${ECHO_CMD} "@dir $${D}"; \
	  done; \
	 ) | sed -e 's|^plan9/bin/auxstats|@(,kmem,2755) &|' \
		-e 's|^plan9/mac|%%SRC%%&|' \
		-e 's|^plan9/unix|%%SRC%%&|' \
		-e 's|^plan9/bin/macedit|%%SRC%%&|' \
		-e 's|^plan9/bin/osxvers|%%SRC%%&|' \
		-e '/^plan9\/dist\//{/spaceglenda100\.png/!s/^/%%SRC%%/;}' \
		-e '/^plan9\/src\//{/src\/mk/!s/^/%%SRC%%/;}' > ${PLIST}

do-install:
	${CP} -a ${WRKSRC} ${STAGEDIR}${PREFIX}

do-install-SRC-off:
	@${RM} -r ${STAGEDIR}${PLAN9}/mac ${STAGEDIR}${PLAN9}/unix \
		${STAGEDIR}${PLAN9}/bin/osxvers ${STAGEDIR}${PLAN9}/bin/macedit
	@${FIND} ${STAGEDIR}${PLAN9}/dist ! -name spaceglenda100.png -delete
	@${FIND} ${STAGEDIR}${PLAN9}/src ! -path '${STAGEDIR}${PLAN9}/src/mk*' \
		-delete

post-install:
	@${FIND} ${STAGEDIR}${PLAN9}/bin -type f | \
		while read file; do \
			case "$$(file -- "$$file")" in \
				*ELF*) \
					${STRIP_CMD} -- "$$file"; \
					;; \
			esac \
		done

post-install-SRC-on:
	@${STRIP_CMD} -- ${STAGEDIR}${PLAN9}/src/cmd/devdraw/o.devdraw

install-user:
	@${MKDIR} ${HOME}/lib
	${INSTALL_DATA} ${PLAN9}/plumb/initial.plumbing ${HOME}/lib/plumbing

.include <bsd.port.mk>
