# New ports collection makefile for: autoconf-archive
# Date Created:	18 October 2006
# Whom:		Martin Kammerhofer
#
# $FreeBSD$
#

PORTNAME=	autoconf-archive
PORTVERSION=	0.${DISTDATE:C/-/./g}
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://autoconf-archive.cryp.to/ \
		http://mitglied.lycos.de/mkamm/distfiles/
DISTNAME=	${PORTNAME}-${DISTDATE}

MAINTAINER=	mkamm@gmx.net
COMMENT=	A set of useful GNU Autoconf macros

DISTDATE=	2009-04-19
USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf:267:env automake:111:env
GNU_CONFIGURE=	yes

PLIST_SUB=	MACRODIR=share/aclocal

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} --install

.if defined(NOPORTDOCS)
do-install:
	cd ${WRKSRC} && ${MAKE} install-dist_aclocalDATA
.endif

# next rule for maintainer use only: automatically create pkg-plist
plist:
	@test -e ${CONFIGURE_COOKIE} || { \
		${ECHO_MSG} >&2 "do 'make configure' first!"; exit 64; }
	cd ${WRKSRC} && ${MAKE} -V DATA | \
	${TR} ' ' '\n' | \
	${SED}  -e 's,^\./m4[a-z]*/,%%MACRODIR%%/,' \
		-e 's,^\./,%%PORTDOCS%%%%DOCSDIR%%/,' \
		-e 's,/htmldoc/,/html/,' \
		-e 's,^[A-Za-z_],%%PORTDOCS%%%%DOCSDIR%%/&,' | \
	${SORT} -u >${PLIST}
	${ECHO_CMD} '%%PORTDOCS%%@dirrm %%DOCSDIR%%/html' >>${PLIST}
	${ECHO_CMD} '%%PORTDOCS%%@dirrm %%DOCSDIR%%' >>${PLIST}

.include <bsd.port.mk>
