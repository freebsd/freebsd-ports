# Created by: Serge Gagnon <serge.gagnon@b2b2c.ca>
# $FreeBSD$

PORTNAME=	plan9port
PORTVERSION=	20140306
PORTREVISION=	1
CATEGORIES=	devel plan9
MASTER_SITES=	http://swtch.com/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of many Plan 9 programs to Unix-like operating systems

LICENSE=	LUCENT
LICENSE_NAME=	Lucent Public License Version 1.02
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		perl5 tar:tgz
USE_PERL5=	build
USE_XORG=	x11 xt xi xaw
WRKSRC=		${WRKDIR}/plan9
PLIST=		${WRKDIR}/.PLIST
SUB_FILES=	pkg-message
REINPLACE_ARGS=	-i ""		# necessary since installs via recursive copy

PLAN9=		${PREFIX}/plan9

EMPTY_DIRS=	plan9/log \
		plan9/bin/lpbin \
		plan9/dist/troff \
		plan9/mail/queue \
		plan9/dist/debian \
		plan9/dist/pkg

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
	${RM} -rf `${FIND} ${WRKSRC} -name .hg -o -name .cvsignore`
	( cd ${WRKDIR} ; \
	  ${FIND} plan9 -type f; for D in ${EMPTY_DIRS}; do \
	    ${ECHO_CMD} "@exec ${MKDIR} ${PREFIX}/$${D}"; \
	  done; \
	  ${FIND} plan9 -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm |'; \
	) | ${PERL} -pe '$$_ =~ s,plan9/bin/auxstats,\@group kmem\n\@mode\
	  2755\n$$&\n\@group\n\@mode,' > ${PLIST}

do-install:
	${CP} -a ${WRKSRC} ${STAGEDIR}${PREFIX}

post-install:
	cd ${STAGEDIR}${PLAN9} && ${SETENV} PLAN9=${PLAN9} \
		PATH=${PATH}:${STAGEDIR}${PLAN9}/bin \
			${SH} lib/moveplan9.sh ${WRKSRC}
	${CHMOD} 01777 ${STAGEDIR}${PLAN9}/news

install-user:
	@${MKDIR} ${HOME}/lib
	${INSTALL_DATA} ${PLAN9}/plumb/initial.plumbing ${HOME}/lib/plumbing

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		Does not install: cleanname not found
.endif

.include <bsd.port.post.mk>
