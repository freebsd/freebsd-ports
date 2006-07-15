# New ports collection makefile for:  gcin
# Date created:                   Feb 18 2004
# Whom:                           Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	gcin
PORTVERSION=	1.2.1
CATEGORIES=	chinese textproc gnome
MASTER_SITES=	http://www.csie.nctu.edu.tw/~cp76/gcin/download/:main \
		http://edt1023.sayya.org/misc/:boshiamy
DISTFILES=	gcin-1.2.1.tar.bz2:main \
		noseeing.tar.gz:boshiamy
EXTRACT_ONLY=	gcin-1.2.1.tar.bz2

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	A traditional chinese input utility in X

USE_X_PREFIX=	YES
USE_BZIP2=	YES
GNU_CONFIGURE=	YES
USE_GNOME=	gtk20
USE_GMAKE=	YES
USE_GCC=	3.4+
INSTALLS_ICONS=	YES
INSTALLS_SHLIB=	YES
OPTIONS=	BOSHIAMY	"enable Boshiamy Input Method"	off
IGNOREFILES=	noseeing.tar.gz

CONFIGURE_ENV+=	"--new_gtk_im=Y"

MAN1=		gcin.1 gcin2tab.1

.include <bsd.port.pre.mk>

.if defined(WITH_BOSHIAMY)
post-extract:
	@${TAR} -C ${WRKSRC}/data/ -zxf ${DISTDIR}/noseeing.tar.gz \
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
