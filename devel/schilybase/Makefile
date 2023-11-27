PORTNAME=	schilybase
PORTREVISION=	1
CATEGORIES=	devel

COMMENT=	Support files and libraries for the schilytools

NLS_USES=	gettext-tools
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS NLS PROFILE
OPTIONS_DEFAULT=DOCS NLS
OPTIONS_SUB=	yes

# do not reorder: order required for build to succeed
BOOTSTRAP_SMAKE?=	yes
COMPONENTS=	conf \
		inc \
		include \
		include/schily \
		libschily \
		libdeflt \
		libscg \
		libscg/scg \
		libxtermcap \
		libcdrdeflt \
		libdbgmalloc \
		libedc \
		libfile \
		libfind \
		libgetopt \
		libhfs_iso \
		libmdigest \
		libparanoia \
		librmt \
		librscg \
		libscgcmd \
		libshedit \
		libsiconv \
		libsiconv/tables \
		libstreamar \
		man \
		man/man5

post-patch-PROFILE-off:
	@${ECHO_MSG} '=> Patching Makefiles to disable profiled libraries'
	@${REINPLACE_CMD} -e '/^MK_FILES/s, [a-z]*_p.mk,,' ${WRKSRC}/*/Makefile

post-build-NLS-on:
	msgfmt --no-convert -o ${WRKDIR}/SCHILY_utils.mo ${WRKSRC}/SCHILY_utils.po

# all languages supported by FreeBSD
_LANGUAGES=	C af am ar be bg ca cs da de el en es et eu fi fr ga he hi hr \
		hu hy is it ja kk ko lt lv mn nb nl nn pl pt ro ru se sk sl sr \
		sv tr uk zh

post-install:
	# this is just a copy of the FreeBSD termcap file, no need to ship it again.
	${RM} ${STAGEDIR}${PREFIX}/etc/termcap

post-install-NLS-on:
	@${ECHO_MSG} '=> installing dummy message catalogues'
	${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/de/LC_MESSAGES
	${INSTALL_DATA} ${WRKDIR}/SCHILY_utils.mo ${STAGEDIR}${PREFIX}/share/locale/de/LC_MESSAGES/SCHILY_utils.mo
.for lang in ${_LANGUAGES:Nde}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${LN} ${STAGEDIR}${PREFIX}/share/locale/de/LC_MESSAGES/SCHILY_utils.mo \
	    ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/SCHILY_utils.mo
.endfor

.include "Makefile.master"
