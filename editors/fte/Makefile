# New ports collection makefile for:	fte
# Date created:				8 May 2000
# Whom:					gelf
#
# $FreeBSD$
#

PORTNAME=		fte
PORTVERSION=		46.5
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}s${PORTVERSION:S/./b/}
EXTRACT_SUFX=		.zip

MAINTAINER=		mail@gelf.com

BUILD_DEPENDS=  	unzip:${PORTSDIR}/archivers/unzip

EXTRACT_CMD=		unzip
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=
USE_XLIB=		yes

ADDITIONAL_DOCS=	about.html \
			cfgfiles.html \
			cmdopt.html \
			colorize.html \
			colors.html \
			command.html \
			contents.html \
			events.html \
			global.html \
			index.html \
			install.html \
			modes.html \
			perftips.html \
			regexp.html \
			status.html

.include <bsd.port.pre.mk>

.include "${FILESDIR}/conffiles"

do-build:
	(cd ${WRKSRC}/src ; ${MAKE} -f fte-unix.mak)
	(cd ${WRKSRC}/config ; ../src/cfte main.fte)

do-install:
	${MKDIR} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/etc/fte
	${MKDIR} ${PREFIX}/etc/fte/kbd
	${MKDIR} ${PREFIX}/etc/fte/menu

	${INSTALL_PROGRAM} ${WRKSRC}/src/xfte ${PREFIX}/bin/fte
	${LN} -sf ${PREFIX}/bin/fte ${PREFIX}/bin/xfte
	${INSTALL_PROGRAM} ${WRKSRC}/src/cfte ${PREFIX}/bin/cfte
	${INSTALL_DATA} ${WRKSRC}/config/fte-new.cnf ${PREFIX}/etc/fte/system.fterc
.for CONFFILE in ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/config/${CONFFILE} ${PREFIX}/etc/fte
.endfor
.for KBDFILE in ${KBDFILES}
	${INSTALL_DATA} ${WRKSRC}/config/kbd/${KBDFILE} ${PREFIX}/etc/fte/kbd
.endfor
	${INSTALL_DATA} ${WRKSRC}/config/menu/m_c.fte ${PREFIX}/etc/fte/menu
	${INSTALL_DATA} ${WRKSRC}/config/menu/m_html.fte ${PREFIX}/etc/fte/menu
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/fte
	for i in $(ADDITIONAL_DOCS); do \
	    ${INSTALL_MAN} ${WRKSRC}/doc/$$i ${PREFIX}/share/doc/fte; \
	done
.endif

.include <bsd.port.post.mk>
