# Ports collection makefile for:	erlang-doc
# Date created:				31 Mar 2002
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	erlang-doc
PORTVERSION=	r10b10
PORTEPOCH=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.erlang.se/doc/doc-5.4.13/pdf/:release \
		http://erlang.org/download/:erlangorg \
		http://www.erlang.se/doc/:erlangse \
		http://www.sics.se/~joe/thesis/:joe \
		http://www.st.se/telecom/eng/projects/:stse \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=     olgeni/:local
DISTFILES=	appmon-2.1.5.pdf:release \
		asn1-1.4.4.9.pdf:release \
		compiler-4.3.12.pdf:release \
		cosEvent-2.1.pdf:release \
		cosEventDomain-1.1.pdf:release \
		cosFileTransfer-1.1.2.pdf:release \
		cosNotification-1.1.2.pdf:release \
		cosProperty-1.1.1.pdf:release \
		cosTime-1.1.pdf:release \
		cosTransactions-1.2.pdf:release \
		crypto-1.4.pdf:release \
		debugger-3.0.1.pdf:release \
		design_principles-5.4.13.pdf:release \
		efficiency_guide-5.4.13.pdf:release \
		embedded-5.4.13.pdf:release \
		erl_interface-3.5.5.pdf:release \
		erts-5.4.13.pdf:release \
		et-1.0.pdf:release \
		getting_started-5.4.13.pdf:release \
		gs-1.5.4.pdf:release \
		ic-4.2.9.pdf:release \
		inets-4.7.2.pdf:release \
		installation_guide-5.4.13.pdf:release \
		jinterface-1.3.pdf:release \
		kernel-2.10.13.pdf:release \
		megaco-3.3.pdf:release \
		mnemosyne-1.2.5.1.pdf:release \
		mnesia-4.2.5.pdf:release \
		mnesia_session-1.1.5.pdf:release \
		oam-5.4.13.pdf:release \
		observer-0.9.6.2.pdf:release \
		odbc-2.0.6.pdf:release \
		orber-3.6.2.pdf:release \
		os_mon-2.0.pdf:release \
		otp_mibs-1.0.4.pdf:release \
		parsetools-1.3.2.pdf:release \
		pman-2.5.2.pdf:release \
		programming_examples-5.4.13.pdf:release \
		reference_manual-5.4.13.pdf:release \
		runtime_tools-1.5.1.1.pdf:release \
		sasl-2.1.1.pdf:release \
		snmp-4.7.1.pdf:release \
		ssh-0.9.1.pdf:release \
		ssl-3.0.11.pdf:release \
		stdlib-1.13.12.pdf:release \
		system_architecture_intro-5.4.13.pdf:release \
		system_principles-5.4.13.pdf:release \
		toolbar-1.2.1.pdf:release \
		tools-2.4.7.pdf:release \
		tutorial-5.4.13.pdf:release \
		tv-2.1.2.pdf:release \
		webtool-0.8.2.pdf:release \
		xmerl-1.0.3.pdf:release \
		course.pdf:erlangorg \
		erlang-book-part1.pdf:erlangorg \
		programming_rules.pdf:erlangse \
		armstrong_thesis_2003.pdf:joe \
		master_thesis_patterns.pdf:local
DIST_SUBDIR=	erlang
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
