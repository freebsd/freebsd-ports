# ex:ts=8
# Ports collection makefile for:  Sather
# Date created:			  Mon Oct 31 22:04:12 PST 1994
# Whom:				  hsu
#
# $FreeBSD$
#

PORTNAME=	sather
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sather compiler

LIB_DEPENDS=	gc.1:${PORTSDIR}/devel/boehm-gc \
		tk83.1:${PORTSDIR}/x11-toolkits/tk83

USE_REINPLACE=	yes
USE_GMAKE=	yes
ALL_TARGET=	full optional
MAN1=		sabrowse.1 sacomp.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/System/Platforms/freebsd
.for file in CONFIG Makefile Platform.module header.h
	@${CP} -f ${FILESDIR}/freebsd-${file} \
		${WRKSRC}/System/Platforms/freebsd/${file}
.endfor

post-patch:
.for file in Boot/sacomp.code/Makefile Browser/Web/convert-1.1 \
	Browser/Web/gen_html_class_index Browser/Web/gen_html_sa_files \
	Browser/Web/gen_html_shortflat Browser/Web/gen_html_top_level \
	Browser/Web/gen_mml_sa_files Browser/Web/gen_mml_shortflat \
	Browser/Web/graph2dot Library/System/unix.sa \
	System/Common/CONFIG.proto System/Platforms/freebsd/CONFIG \
	System/Platforms/X/Platform.module debian/bin-wrapper
	@${REINPLACE_CMD} -e 's|%%VERSION%%|${PORTVERSION}|g ; \
		 s|%%CC%%|${CC}|g ; \
		 s|%%CFLAGS%%|${CFLAGS}|g ; \
		 s|%%GMAKE%%|${GMAKE}|g ; \
		 s|%%PREFIX%%|${PREFIX}|g ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		 s|%%X11BASE%%|${X11BASE}|g ; \
		 s|CONFIG_PLATFORMS|unix|g ; \
		 s|CONFIG_DEFAULT_PLATFORM|freebsd|g ; \
		 s|/usr/bin/tclsh|${LOCALBASE}/bin/tclsh8.3|g' ${WRKSRC}/${file}
.endfor

post-build:
.for file in sather-tutorial.texinfo sather-mode.texinfo sather.texinfo
	cd ${WRKSRC}/Emacs && /usr/bin/makeinfo --no-split ${file}
.endfor

do-install:
	@${MKDIR} ${PREFIX}/lib/sather/Bin
.for file in sabrowse sacomp
	${INSTALL_PROGRAM} ${WRKSRC}/Bin/${file} ${PREFIX}/lib/sather/Bin
.endfor
.for file in PP gen_html saprep
	${INSTALL_SCRIPT} ${WRKSRC}/Bin/${file} ${PREFIX}/lib/sather/Bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/debian/bin-wrapper ${PREFIX}/lib/sather/Bin
.for link in sabrowse sacomp
	${LN} -sf ${PREFIX}/lib/sather/Bin/bin-wrapper ${PREFIX}/bin/${link}
.endfor
.for obj in Browser Library System/Common System/Debug System/FORBID \
	System/Platforms/X System/Platforms/dualgui System/Platforms/f77 \
	System/Platforms/freebsd System/Platforms/gui System/Platforms/tcltk
	${TAR} -C ${WRKSRC} -cf - \
		--exclude "ActiveThreads" --exclude "Brahma" \
		--exclude "CONFIG.proto" --exclude "Siva" \
		--exclude "dual_gui_server.code" --exclude "*.bak" \
		--exclude "*.config" --exclude "*.orig" \
		--exclude "*Makefile*" ${obj} | \
		${TAR} -C ${PREFIX}/lib/sather --unlink -xf -
	@${CHOWN} -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/sather/${obj}
.endfor
.for file in sabrowse.1 sacomp.1
	${INSTALL_MAN} ${WRKSRC}/Doc/man/man1/${file} ${MANPREFIX}/man/man1
.endfor
.for file in sather-mode.info sather-tutorial.info sather.info
	${INSTALL_DATA} ${WRKSRC}/Emacs/${file} ${PREFIX}/info
	@install-info ${PREFIX}/info/${file} ${PREFIX}/info/dir
.endfor
.for file in hl319.el sather-lib.el sather-module.el sather.el
	${INSTALL_DATA} ${WRKSRC}/Emacs/${file} ${PREFIX}/share/emacs/site-lisp
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/Doc --exclude '*GPL' --exclude man -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
