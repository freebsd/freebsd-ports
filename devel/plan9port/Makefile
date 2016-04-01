# Created by: Serge Gagnon <serge.gagnon@b2b2c.ca>
# $FreeBSD$

PORTNAME=	plan9port
PORTVERSION=	20140306
PORTREVISION=	5
CATEGORIES=	devel plan9
MASTER_SITES=	https://plan9port.googlecode.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of many Plan 9 programs to Unix-like operating systems

LICENSE=	LUCENT
LICENSE_NAME=	Lucent Public License Version 1.02
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_ia64=	does not install: cleanname not found
BROKEN_sparc64=	does not install: cleanname not found

RUN_DEPENDS=	rc:shells/rc

USES=		perl5 shebangfix tar:tgz
SHEBANG_LANG=	rc
rc_OLD_CMD=	/bin/rc
rc_CMD=		${LOCALBASE}/bin/rc
SHEBANG_FILES=	acid/transcript \
		acid/window \
		mac/9term.app/Contents/MacOS/9term \
		mac/Plumb.app/Contents/MacOS/plumb \
		src/cmd/9660/mk9660.rc \
		src/cmd/dict/egfix \
		src/cmd/dict/egfix2 \
		src/cmd/dict/gefix \
		src/cmd/dict/getneeds \
		src/cmd/lp/lpsend.rc \
		src/cmd/map/map.rc \
		src/cmd/map/mapdemo.rc \
		src/cmd/spell/spell.rc \
		src/cmd/upas/filterkit/pipefrom.sample \
		unix/man/fixurls
USE_PERL5=	build
USE_XORG=	x11 xt xi xaw
WRKSRC=		${WRKDIR}/plan9
PLIST=		${WRKDIR}/.PLIST
SUB_FILES=	pkg-message
REINPLACE_ARGS=	-i ""		# necessary since installs via recursive copy

PLAN9=		${PREFIX}/plan9

EMPTY_DIRS=	plan9/mail/queue \
		plan9/log \
		plan9/dist/debian \
		plan9/dist/pkg \
		plan9/dist/troff \
		plan9/bin/lpbin

post-extract:
	${MV} ${WRKDIR}/plan9port ${WRKDIR}/plan9

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

do-build:
	cd ${WRKSRC} && CC9="${CC}" ./INSTALL

# Dynamic PLIST sucks, but it's over 8K lines, which sucks even more :(
post-build:
	${RM} -rf `${FIND} ${WRKSRC}/dist -type f ! -regex ".*\.png"`
	${RM} -rf `${FIND} ${WRKSRC} -name .hg -o -name .hgignore \
		-o -name .hgtags -o -name .cvsignore`
	@( cd ${WRKDIR} ; \
	  ${FIND} plan9 -type f; \
	  ${ECHO_CMD} "@dir(,,1777) plan9/news"; \
	  for D in ${EMPTY_DIRS}; do \
	    ${ECHO_CMD} "@dir $${D}"; \
	  done; \
	 ) | sed -e '/plan9\/bin\/auxstats/s|^|\@\(,kmem,2755\) |' > ${PLIST}

do-install:
	${CP} -a ${WRKSRC} ${STAGEDIR}${PREFIX}

post-install:
	cd ${STAGEDIR}${PLAN9} && ${SETENV} PLAN9=${PLAN9} \
		PATH=${PATH}:${STAGEDIR}${PLAN9}/bin \
			${SH} lib/moveplan9.sh ${WRKSRC}

install-user:
	@${MKDIR} ${HOME}/lib
	${INSTALL_DATA} ${PLAN9}/plumb/initial.plumbing ${HOME}/lib/plumbing

.include <bsd.port.mk>
