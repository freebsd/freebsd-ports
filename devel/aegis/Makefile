# Created by: alepulver
# $FreeBSD$

PORTNAME=	aegis
PORTVERSION=	4.25
DISTVERSIONSUFFIX=	.D510
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	aryeh.friedman@gmail.com
COMMENT=	Transaction-based software configuration management system

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	tkdiff:textproc/tkdiff

USES=		gettext ghostscript groff perl5 tk
USE_GNOME=	libxml2
USE_GCC=	any
GNU_CONFIGURE=	yes
CPPFLAGS+=	"-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--with-nlsdir="${PREFIX}/share/locale"
CONFIGURE_ENV=	WISH="${WISH}"
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

# GCC 6 switched to -std=gnu++14 by default, which breaks the port (bug
# 219284). Explicitly use the previous default to keep things going.
USE_CXXSTD=	gnu++98

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

# XXX Manpages are installed into ${DATADIR} too -- there's no easy way to
#     stop this because we don't have Makefile.am provided.  Maintainer will
#     sort this with upstream.

PORTDATA=	*
PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
# Avoid "2>/dev/null" redirect in csh (ends up with empty manpath).
	@${REINPLACE_CMD} -Ee 's|(MANPATH_PROG) 2>/dev/null|\1|' \
		${WRKSRC}/configure
# Fix path to Tk interpreter.
	@cd ${WRKSRC}/script && ${REINPLACE_CMD} -e 's|wish |${WISH} |' \
		aebuffy.in aecomp.in aexver.in tkaeca.in tkaegis.in tkaenc.in \
		tkaepa.in tkaer.in xaegis.in
# Import global variable "datadir" inside function (not found otherwise).
	@${REINPLACE_CMD} -e 's|global lib|& datadir|' \
		${WRKSRC}/script/xaegis.in

post-configure:
.if empty(PORT_OPTIONS:MNLS)
	${REINPLACE_CMD} -e 's|HAVE_MSGFMT = yes|HAVE_MSGFMT = no|' \
		${WRKSRC}/Makefile
.endif

post-install:
	${MKDIR} -p ${STAGEDIR}${PREFIX}/com/aegis
# Fails to reinstall because keeps track of created directories, so make it
# forget that, by recreating them on each install.
	@${FIND} ${WRKSRC} -type f -name ".*dir" -delete

.include <bsd.port.mk>
