# New ports collection makefile for:	fourcdns
# Date created:		01 Jan 2007
# Whom:			Ron Scheckelhoff <rscheckelhoff@fourcalorieservers.com>
#
# $FreeBSD$
#

PORTNAME=	fourcdns
PORTVERSION=	1.1.0
CATEGORIES=	dns
MASTER_SITES=	http://www.fourcalorieservers.com/ports/dns/fourcdns/

MAINTAINER=	rscheckelhoff@fourcalorieservers.com
COMMENT=	A simple DNS server

PLIST_FILES=	bin/fourcdns

NO_BUILD=	yes
USE_LDCONFIG=	yes

MAN7=		fourcdns.7
PORTDOCS=	fourcdns.pdf

# distfile contains i386 binary
ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if ${OSVERSION}>=600000
EXEFILE=	fourcdns6
MGRGUI=	fourcdnsmgr6
LIBWXBASE=	wxversion6/libwx_base-2.6.so.0
LIBWXBASENET=	wxversion6/libwx_base_net-2.6.so.0
LIBWXBASEXML=	wxversion6/libwx_base_xml-2.6.so.0
LIBWXX11UNIVADV=	wxversion6/libwx_x11univ_adv-2.6.so.0
LIBWXX11UNIVCORE=	wxversion6/libwx_x11univ_core-2.6.so.0
LIBWXX11UNIVHTML=	wxversion6/libwx_x11univ_html-2.6.so.0
LIBWXX11UNIVQA=		wxversion6/libwx_x11univ_qa-2.6.so.0
LIBWXX11UNIVXRC=	wxversion6/libwx_x11univ_xrc-2.6.so.0
LIBWXX11UNIVMED=	wxversion6/libwx_x11univ_media-2.6.so.0
.else
EXEFILE=	fourcdns6
MGRGUI=	fourcdnsmgr5
LIBWXBASE=	wxversion5/libwx_base-2.6.so.5
LIBWXBASENET=	wxversion5/libwx_base_net-2.6.so.5
LIBWXBASEXML=	wxversion5/libwx_base_xml-2.6.so.5
LIBWXX11UNIVADV=	wxversion5/libwx_x11univ_adv-2.6.so.5
LIBWXX11UNIVCORE=	wxversion5/libwx_x11univ_core-2.6.so.5
LIBWXX11UNIVHTML=	wxversion5/libwx_x11univ_html-2.6.so.5
LIBWXX11UNIVQA=		wxversion5/libwx_x11univ_qa-2.6.so.5
LIBWXX11UNIVXRC=	wxversion5/libwx_x11univ_xrc-2.6.so.5
LIBWXX11UNIVMED=	wxversion5/libwx_x11univ_media-2.6.so.5
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${EXEFILE} ${PREFIX}/bin/fourcdns
	${MKDIR} ${PREFIX}/zerocaloriedns
	${INSTALL_PROGRAM} ${WRKSRC}/${MGRGUI} ${PREFIX}/zerocaloriedns/fourcdnsmgr6
	${INSTALL_PROGRAM} ${WRKSRC}/${MGRGUI} ${PREFIX}/bin/fourcdnsmgr6
	${INSTALL_PROGRAM} ${WRKSRC}/${EXEFILE} ${PREFIX}/zerocaloriedns/fourcdns
	${INSTALL_PROGRAM} ${WRKSRC}/${LIBWXBASE} ${PREFIX}/lib/libwx_base-2.6.so.0
	${INSTALL_PROGRAM} ${WRKSRC}/${LIBWXBASENET} ${PREFIX}/lib/libwx_base_net-2.6.so.0
	${INSTALL_PROGRAM} ${WRKSRC}/${LIBWXBASEXML} ${PREFIX}/lib/libwx_base_xml-2.6.so.0
	${INSTALL_PROGRAM} ${WRKSRC}/${LIBWXX11UNIVADV} ${PREFIX}/lib/libwx_x11univ_adv-2.6.so.0
	${INSTALL_PROGRAM} ${WRKSRC}/${LIBWXX11UNIVCORE} ${PREFIX}/lib/libwx_x11univ_core-2.6.so.0
	${INSTALL_PROGRAM} ${WRKSRC}/${LIBWXX11UNIVHTML} ${PREFIX}/lib/libwx_x11univ_html-2.6.so.0
	${INSTALL_PROGRAM} ${WRKSRC}/${LIBWXX11UNIVQA} ${PREFIX}/lib/libwx_x11univ_qa-2.6.so.0
	${INSTALL_PROGRAM} ${WRKSRC}/${LIBWXX11UNIVXRC} ${PREFIX}/lib/libwx_x11univ_xrc-2.6.so.0
	${INSTALL_PROGRAM} ${WRKSRC}/${LIBWXX11UNIVMED} ${PREFIX}/lib/libwx_x11univ_media-2.6.so.0
	${INSTALL_MAN} ${WRKSRC}/fourcdns.7 ${MAN7PREFIX}/man/man7/fourcdns.7
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/fourcdns.pdf ${DOCSDIR}/fourcdns.pdf
	${INSTALL_DATA} ${WRKSRC}/index.htm ${PREFIX}/zerocaloriedns/index.htm
	${INSTALL_DATA} ${WRKSRC}/zerocaloriedns.set ${PREFIX}/zerocaloriedns/zerocaloriedns.set
	${INSTALL_DATA} ${WRKSRC}/license.txt ${PREFIX}/zerocaloriedns/license.txt
	${INSTALL_DATA} ${WRKSRC}/wxWidgetsNotes.txt ${PREFIX}/zerocaloriedns/wxWidgetsNotes.txt
	${INSTALL_DATA} ${WRKSRC}/wxWidgetsLicense.txt ${PREFIX}/zerocaloriedns/wxWidgetsLicense.txt
.include <bsd.port.post.mk>
