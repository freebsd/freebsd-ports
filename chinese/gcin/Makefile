# New ports collection makefile for:  gcin
# Date created:                   Feb 18 2004
# Whom:                           Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	gcin
PORTVERSION=	1.1.9
CATEGORIES=	chinese textproc gnome
MASTER_SITES=	http://www.csie.nctu.edu.tw/~cp76/gcin/download/ \
		http://edt1023.sayya.org/misc/
.if defined(WITH_BOSHIAMY)
DISTFILES=	${GCINFILE} ${BOSHIAMYFILE}
EXTRACT_ONLY=	${GCINFILE}
.endif

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	A traditional chinese input utility in X

USE_X_PREFIX=	YES
USE_BZIP2=	YES
GNU_CONFIGURE=	YES
USE_GNOME=	gtk20
USE_GMAKE=	YES

CONFIGURE_ENV+=	"--new_gtk_im=Y"

MAN1=		gcin.1 gcin2tab.1

.include <bsd.port.pre.mk>

pre-extract:
	@${ECHO_MSG} ''
	@${ECHO_MSG} 'gcin has the following tunable option:'
	@${ECHO_MSG} '    WITH_BOSHIAMY  - enable Boshiamy support'
	@${ECHO_MSG} ''
	@${ECHO_MSG} 'Example:  "make WITH_BOSHIAMY=yes install clean" '
	@${ECHO_MSG} ''

.if ${OSVERSION} <= 500034
USE_GCC=	3.4
.endif

.if defined(WITH_BOSHIAMY)
IGNOREFILES=	${BOSHIAMYFILE}
GCINFILE=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
BOSHIAMYFILE=	noseeing.tar.gz
post-extract:
	@${TAR} -C ${WRKSRC}/data/ -zxf ${DISTDIR}/${BOSHIAMYFILE} \
		noseeing.cin
	@${REINPLACE_CMD} -e 's,cj.gtab,cj.gtab noseeing.gtab,' \
		${WRKSRC}/data/Makefile
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's,gcin.png,${PREFIX}/share/icons/gcin.png,' \
		${WRKSRC}/menu/gcin-setup.desktop
	@${REINPLACE_CMD} -e 's/&//; s/bash/sh/; \
		s/QT_IM_DIR=\/usr/QT_IM_DIR=$$prefix/; \
		s/mandir=$$datadir/mandir=$$prefix/; \
		s/\/usr\/share/$$prefix\/share/; \
		109,110 s/control-center-2\.0/gnome\/control-center-2\.0/; \
		s/gcc/$$CC/; s/gcin-$$GCIN_VERSION/gcin/' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's/modify-XIM //; 8,10 d' ${WRKSRC}/scripts/Makefile
	@${REINPLACE_CMD} -e 's/bash/sh/;' ${WRKSRC}/scripts/gcin-user-setup
	@${REINPLACE_CMD} -e 's/bash/sh/; s/&//; s/opt\/gnome/usr\/X11R6/;' \
		${WRKSRC}/scripts/utf8-edit
	@${REINPLACE_CMD} -e 's,gcin-im-client.h,im-client/gcin-im-client.h,' \
		${WRKSRC}/gtk-im/gtkimcontextgcin.c

.if defined(WITH_BOSHIAMY)
post-patch:
PLIST_SUB+=	BOSHIAMY=""
.else
PLIST_SUB+=	BOSHIAMY="@comment "
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in Changelog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@gtk-query-immodules-2.0 > ${PREFIX}/etc/gtk-2.0/gtk.immodules
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'

.include <bsd.port.post.mk>
