# Ports collection makefile for:	erlang-doc
# Date created:				31 Mar 2002
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	erlang-doc
PORTVERSION=	8.1
CATEGORIES=	lang
MASTER_SITES=	http://www.erlang.org/doc/r8b/pdf/
DISTFILES=      appmon-2.1.0.pdf asn1-1.3.2.pdf comet-1.1.1.pdf \
		compiler-4.0.pdf cosEvent-2.0.pdf cosFileTransfer-1.0.2.pdf \
		cosNotification-1.0.5.pdf cosProperty-1.0.1.pdf \
		cosTime-1.0.1.1.pdf cosTransactions-1.1.1.1.pdf \
		crypto-1.1.2.pdf debugger-2.0.pdf \
		design_principles-5.1.1.pdf efficiency_guide-5.1.1.pdf \
		embedded-5.1.1.pdf erl_interface-3.3.0.pdf erts-5.1.1.pdf \
		eva-2.0.2.1.pdf extensions-5.1.1.pdf \
		getting_started-5.1.1.pdf gs-1.4.0.pdf ic-4.1.2.pdf \
		inets-2.6.5.pdf installation_guide-5.1.1.pdf \
		jinterface-1.2.1.pdf kernel-2.7.2.pdf megaco-1.0.3.pdf \
		mnemosyne-1.2.5.pdf mnesia-4.0.2.pdf \
		mnesia_session-1.1.4.pdf oam-5.1.1.pdf odbc-0.9.1.pdf \
		orber-3.2.12.pdf os_mon-1.5.0.pdf parsetools-1.1.pdf \
		pman-2.4.1.pdf runtime_tools-1.2.1.pdf sasl-1.9.3.pdf \
		snmp-3.3.5.pdf ssl-2.3.4.pdf stdlib-1.10.1.pdf \
		system_architecture_intro-5.1.1.pdf \
		system_principles-5.1.1.pdf toolbar-1.1.0.pdf \
		tools-2.0.1.pdf tutorial-5.1.1.pdf tv-2.0.4.pdf \
		webtool-0.7.pdf

DIST_SUBDIR=	erlang
EXTRACT_ONLY=

MAINTAINER=	olgeni@FreeBSD.org

NO_BUILD=	yes

do-install:
	@${MKDIR} ${LOCALBASE}/share/doc/erlang
.for FILE in ${DISTFILES}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${FILE} ${LOCALBASE}/share/doc/erlang
.endfor

.include <bsd.port.mk>
