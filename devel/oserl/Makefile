# $FreeBSD$

PORTNAME=	oserl
PORTVERSION=	3.2.4
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	SMPP library for Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang \
		txt2tags:${PORTSDIR}/textproc/txt2tags
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
		common_lib>=3.3.4:${PORTSDIR}/devel/common_lib

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GITHUB=	yes
GH_ACCOUNT=	iamaleksey
GH_PROJECT=	oserl
GH_COMMIT=	f14115d
GH_TAGNAME=	${PORTVERSION}

USE_GMAKE=	yes
USE_DOS2UNIX=	Makefile
ALL_TARGET=	compile doc

MAN1=		oserl.1
MAN3=		gen_esme.3 gen_esme_session.3 gen_mc.3 gen_mc_session.3 \
		smpp_base.3 smpp_base_syntax.3 smpp_disk_log_hlr.3 smpp_error.3 \
		smpp_log_mgr.3 smpp_operation.3 smpp_param_syntax.3 \
		smpp_pdu_syntax.3 smpp_ref_num.3 smpp_req_tab.3 smpp_sm.3 \
		smpp_tty_log_hlr.3

.include <bsd.port.options.mk>

post-extract:
# Trick rebar into locating the oserl include files (see also patch-rebar.config)
	@${LN} -s ${WRKSRC} ${WRKDIR}/${PORTNAME}
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
	@${MKDIR} ${PREFIX}/lib/erlang/lib/oserl-${PORTVERSION}
	@${MKDIR} ${PREFIX}/lib/erlang/lib/oserl-${PORTVERSION}/ebin
	@${MKDIR} ${PREFIX}/lib/erlang/lib/oserl-${PORTVERSION}/include
	@${MKDIR} ${PREFIX}/lib/erlang/lib/oserl-${PORTVERSION}/src
	@${INSTALL_DATA} ${WRKSRC}/ebin/* ${PREFIX}/lib/erlang/lib/oserl-${PORTVERSION}/ebin
	@${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/lib/erlang/lib/oserl-${PORTVERSION}/include
	@${INSTALL_DATA} ${WRKSRC}/src/* ${PREFIX}/lib/erlang/lib/oserl-${PORTVERSION}/src

.include <bsd.port.mk>
