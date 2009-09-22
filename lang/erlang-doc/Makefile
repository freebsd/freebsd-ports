# Ports collection makefile for:	erlang-doc
# Date created:				31 Mar 2002
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	erlang-doc
PORTVERSION=	r13b02
PORTEPOCH=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.erlang.org/documentation/doc-5.7.3/pdf/:release \
		http://www.colby.tv/mirror/erlang-doc/r13b02/:release \
		http://erlang.org/download/:erlangorg \
		http://www.erlang.se/doc/:erlangse \
		http://www.erlang.se/publications/:publications \
		http://www.sics.se/~joe/thesis/:joe \
		http://www.st.se/telecom/eng/projects/:stse \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	olgeni/:local
DISTFILES=	appmon-2.1.10.1.pdf:release \
		asn1-1.6.11.pdf:release \
		common_test-1.4.5.pdf:release \
		compiler-4.6.3.pdf:release \
		cosEvent-2.1.6.pdf:release \
		cosEventDomain-1.1.6.pdf:release \
		cosFileTransfer-1.1.8.pdf:release \
		cosNotification-1.1.11.pdf:release \
		cosProperty-1.1.9.pdf:release \
		cosTime-1.1.6.pdf:release \
		cosTransactions-1.2.7.pdf:release \
		crypto-1.6.1.pdf:release \
		debugger-3.2.pdf:release \
		design_principles-5.7.3.pdf:release \
		dialyzer-2.0.0.pdf:release \
		docbuilder-0.9.8.5.pdf:release \
		edoc-0.7.6.4.pdf:release \
		efficiency_guide-5.7.3.pdf:release \
		embedded-5.7.3.pdf:release \
		erl_interface-3.6.3.pdf:release \
		erts-5.7.3.pdf:release \
		et-1.3.2.pdf:release \
		eunit-2.1.3.pdf:release \
		getting_started-5.7.3.pdf:release \
		gs-1.5.10.pdf:release \
		ic-4.2.22.pdf:release \
		inets-5.1.3.pdf:release \
		installation_guide-5.7.3.pdf:release \
		inviso-0.6.pdf:release \
		jinterface-1.5.1.pdf:release \
		kernel-2.13.3.pdf:release \
		megaco-3.11.3.pdf:release \
		mnesia-4.4.11.pdf:release \
		oam-5.7.3.pdf:release \
		observer-0.9.8.1.pdf:release \
		odbc-2.10.5.pdf:release \
		orber-3.6.13.pdf:release \
		os_mon-2.2.3.pdf:release \
		otp_mibs-1.0.5.pdf:release \
		parsetools-2.0.pdf:release \
		percept-0.8.2.pdf:release \
		pman-2.7.pdf:release \
		programming_examples-5.7.3.pdf:release \
		public_key-0.3.pdf:release \
		reference_manual-5.7.3.pdf:release \
		reltool-0.5.pdf:release \
		runtime_tools-1.8.1.pdf:release \
		sasl-2.1.7.pdf:release \
		snmp-4.13.5.pdf:release \
		ssh-1.1.6.pdf:release \
		ssl-3.10.4.pdf:release \
		stdlib-1.16.3.pdf:release \
		syntax_tools-1.6.3.pdf:release \
		system_architecture_intro-5.7.3.pdf:release \
		system_principles-5.7.3.pdf:release \
		test_server-3.3.4.pdf:release \
		toolbar-1.4.pdf:release \
		tools-2.6.4.pdf:release \
		tutorial-5.7.3.pdf:release \
		tv-2.1.4.3.pdf:release \
		webtool-0.8.4.pdf:release \
		xmerl-1.2.1.pdf:release \
		erlang-book-part1.pdf:erlangorg \
		armstrong_thesis_2003.pdf:joe \
		bjarnelic.pdf:publications \
		mnesia_overview.pdf:publications \
		programming_rules.pdf:erlangse \
		master_thesis_patterns.pdf:local
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Documentation (PDF) for the Erlang/OTP system

NO_BUILD=	yes

do-install:
	@${MKDIR} ${LOCALBASE}/share/doc/erlang
.for FILE in ${DISTFILES}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$(expr ${FILE} : '\([^:]*\)') ${LOCALBASE}/share/doc/erlang
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
