# New ports collection makefile for:  gcin
# Date created:                   Feb 18 2004
# Whom:                           Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	gcin
PORTVERSION=	1.3.4
CATEGORIES=	chinese textproc gnome
MASTER_SITES=	http://cle.linux.org.tw/gcin/download/:main \
		http://ftp.twaren.net/local-distfiles/gcin/:main \
		http://yilan.twbbs.org/chinsan/gcin/:main \
		LOCAL/chinsan:main
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:main
EXTRACT_ONLY=	gcin-${PORTVERSION}.tar.bz2

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	A traditional chinese input utility in X

USE_BZIP2=	YES
HAS_CONFIGURE=	YES
USE_GNOME=	gtk20
USE_GMAKE=	YES
USE_GCC=	3.4+
INSTALLS_ICONS=	YES
USE_LDCONFIG=	YES
OPTIONS=	BOSHIAMY	"enable Boshiamy Input Method"	off

MAN1=		gcin.1 gcin2tab.1

.include <bsd.port.pre.mk>

.if defined(WITH_BOSHIAMY)
MASTER_SITES+=	http://edt1023.sayya.org/gcin/:boshiamy
DISTFILES+=	${BOSHIAMY_FILE}:boshiamy
BOSHIAMY_FILE=	noseeing-8.tar.gz
post-extract:
	@${TAR} -C ${WRKSRC}/data/ -zxf ${DISTDIR}/${BOSHIAMY_FILE} \
		noseeing.cin
	@${REINPLACE_CMD} -e 's,cj.gtab,cj.gtab noseeing.gtab,' \
		${WRKSRC}/data/Makefile
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's,&,,; 1 s,bash,sh,; \
		s,QT_IM_DIR=/usr,QT_IM_DIR=$$prefix,; \
		s,mandir=$$datadir,mandir=$$prefix,; \
		s,/usr/share,$$prefix/share,; s,libdir)\/gcin,libdir),; \
		140 s,control-center-2\.0,gnome\/control-center-2\.0,g; \
		s,gcc,$$CC,; s,gcin-$$GCIN_VERSION,gcin,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,\/usr\/share,$$(prefix)\/share,' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/usr/local,/usr,g' \
		${WRKSRC}/gtk-im/Makefile ${WRKSRC}/menu/Makefile
	@${REINPLACE_CMD} -e 's,/usr/lib,${LOCALBASE}/lib,g; \
		s,/usr/include,${X11BASE}/include,g; s,Xft2/X11/Xft,X11/Xft,' \
		${WRKSRC}/qt-im/Makefile
	@${REINPLACE_CMD} -e 's,modify-XIM ,,; 8,10 d' ${WRKSRC}/scripts/Makefile
	@${REINPLACE_CMD} -e 's,bash,sh,; s/&//; s,/opt/gnome,${X11BASE},;' \
		${WRKSRC}/scripts/utf8-edit ${WRKSRC}/scripts/gcin-user-setup \
		${WRKSRC}/scripts/gtab.append_prepare
	@${REINPLACE_CMD} -e 's,wget,fetch,' ${WRKSRC}/scripts/noseeing-inst
	@${REINPLACE_CMD} -e 's,gcin-im-client.h,im-client/gcin-im-client.h,;' \
		${WRKSRC}/gtk-im/gtkimcontextgcin.c
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${X11BASE},' \
		${WRKSRC}/IMdkit/lib/Makefile ${WRKSRC}/Makefile \
		${WRKSRC}/qt-im/Makefile ${WRKSRC}/scripts/modify-XIM \
		${WRKSRC}/scripts/utf8-edit
	@${REINPLACE_CMD} -e '/make/ d' ${WRKSRC}/IMdkit/lib/Makefile

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
