# $FreeBSD$

PORTNAME=	common_lib
PORTVERSION=	3.3.4
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Library of commonly used Erlang functions

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang \
		txt2tags:${PORTSDIR}/textproc/txt2tags \
		iconv:${PORTSDIR}/converters/libiconv
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GITHUB=	yes
GH_ACCOUNT=	iamaleksey
GH_PROJECT=	common_lib
GH_COMMIT=	c242861
GH_TAGNAME=	${PORTVERSION}

USE_GMAKE=	yes
USE_DOS2UNIX=	Makefile
ALL_TARGET=	compile doc

MAN1=		common_lib.1
MAN3=		cl_application.3 cl_binary.3 cl_calendar.3 cl_consumer.3 \
		cl_csv.3 cl_dqueue.3 cl_lists.3 cl_math.3 cl_pool.3 cl_queue.3 \
		cl_queue_srv.3 cl_queue_tab.3 cl_stats.3 cl_string.3 cl_timer.3

.include <bsd.port.options.mk>

post-extract:
	@${REINPLACE_CMD} -e "s@&lt;@<@g" -e "s@&gt;@>@g" ${WRKSRC}/doc/*.ndoc

do-install:
.for manpage in ${MAN1} ${MAN3}
	@iconv -f UTF-8 -t ISO-8859-1 ${WRKSRC}/doc/man/${manpage} > ${WRKSRC}/doc/man/${manpage}.iconv
.endfor
.for manpage in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/doc/man/${manpage}.iconv ${MAN1PREFIX}/man/man1/${manpage}
.endfor
.for manpage in ${MAN3}
	@${INSTALL_MAN} ${WRKSRC}/doc/man/${manpage}.iconv ${MAN3PREFIX}/man/man3/${manpage}
.endfor
	@${MKDIR} ${PREFIX}/lib/erlang/lib/common_lib-${PORTVERSION}
	@${MKDIR} ${PREFIX}/lib/erlang/lib/common_lib-${PORTVERSION}/ebin
	@${MKDIR} ${PREFIX}/lib/erlang/lib/common_lib-${PORTVERSION}/src
	@${INSTALL_DATA} ${WRKSRC}/ebin/* ${PREFIX}/lib/erlang/lib/common_lib-${PORTVERSION}/ebin
	@${INSTALL_DATA} ${WRKSRC}/src/* ${PREFIX}/lib/erlang/lib/common_lib-${PORTVERSION}/src

.include <bsd.port.mk>
