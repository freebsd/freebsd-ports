# $FreeBSD$

PORTNAME=	pgloader
PORTVERSION=	3.6.2
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
MASTER_SITES=	https://beta.quicklisp.org/archive/alexandria/2020-09-25/:alexandria \
		https://beta.quicklisp.org/archive/anaphora/2021-01-24/:anaphora \
		https://beta.quicklisp.org/archive/asdf-finalizers/2017-04-03/:asdffinalizers \
		https://beta.quicklisp.org/archive/asdf-system-connections/2017-01-24/:asdfsystemconnections \
		https://beta.quicklisp.org/archive/babel/2020-09-25/:babel \
		https://beta.quicklisp.org/archive/bordeaux-threads/2020-06-10/:bordeauxthreads \
		https://beta.quicklisp.org/archive/buildapp/2015-12-18/:buildapp \
		https://beta.quicklisp.org/archive/cffi/2020-07-15/:cffi \
		https://beta.quicklisp.org/archive/chipz/2019-02-02/:chipz \
		https://beta.quicklisp.org/archive/chunga/2020-04-27/:chunga \
		https://beta.quicklisp.org/archive/cl-abnf/2020-03-25/:clabnf \
		https://beta.quicklisp.org/archive/cl-base64/2020-10-16/:clbase64 \
		https://beta.quicklisp.org/archive/cl-containers/2020-04-27/:clcontainers \
		https://beta.quicklisp.org/archive/cl-fad/2021-01-24/:clfad \
		https://beta.quicklisp.org/archive/cl-interpol/2020-12-20/:clinterpol \
		https://beta.quicklisp.org/archive/cl-log/2013-01-28/:cllog \
		https://beta.quicklisp.org/archive/cl-markdown/2019-12-27/:clmarkdown \
		https://beta.quicklisp.org/archive/cl-mssql/2021-01-24/:clmssql \
		https://beta.quicklisp.org/archive/cl-mustache/2020-03-25/:clmustache \
		https://beta.quicklisp.org/archive/cl-ppcre/2019-05-21/:clppcre \
		https://beta.quicklisp.org/archive/cl-sqlite/2019-08-13/:clsqlite \
		https://beta.quicklisp.org/archive/cl-unicode/2021-01-24/:clunicode \
		https://beta.quicklisp.org/archive/cl-utilities/2010-10-06/:clutilities \
		https://beta.quicklisp.org/archive/cl+ssl/2021-01-24/:clssl \
		https://beta.quicklisp.org/archive/closer-mop/2021-01-24/:closermop \
		https://beta.quicklisp.org/archive/closure-common/2018-10-18/:closurecommon \
		https://beta.quicklisp.org/archive/command-line-arguments/2020-03-25/:commandlinearguments \
		https://beta.quicklisp.org/archive/cxml/2020-06-10/:cxml \
		https://beta.quicklisp.org/archive/drakma/2019-11-30/:drakma \
		https://beta.quicklisp.org/archive/dynamic-classes/2013-01-28/:dynamicclasses \
		https://beta.quicklisp.org/archive/esrap/2020-12-20/:esrap \
		https://beta.quicklisp.org/archive/flexi-streams/2020-09-25/:flexistreams \
		https://beta.quicklisp.org/archive/garbage-pools/2021-01-24/:garbagepools \
		https://beta.quicklisp.org/archive/global-vars/2014-11-06/:globalvars \
		https://beta.quicklisp.org/archive/ieee-floats/2017-08-30/:ieeefloats \
		https://beta.quicklisp.org/archive/ironclad/2021-01-24/:ironclad \
		https://beta.quicklisp.org/archive/iterate/2020-06-10/:iterate \
		https://beta.quicklisp.org/archive/local-time/2021-01-24/:localtime \
		https://beta.quicklisp.org/archive/lparallel/2016-08-25/:lparallel \
		https://beta.quicklisp.org/archive/md5/2018-02-28/:md5 \
		https://beta.quicklisp.org/archive/metabang-bind/2020-02-18/:metabangbind \
		https://beta.quicklisp.org/archive/metatilities-base/2019-12-27/:metatilitiesbase \
		https://beta.quicklisp.org/archive/named-readtables/2021-01-24/:namedreadtables \
		https://beta.quicklisp.org/archive/parse-number/2018-02-28/:parsenumber \
		https://beta.quicklisp.org/archive/postmodern/2021-01-24/:postmodern \
		https://beta.quicklisp.org/archive/puri/2020-10-16/:puri \
		https://beta.quicklisp.org/archive/py-configparser/2017-08-30/:pyconfigparser \
		https://beta.quicklisp.org/archive/quri/2020-12-20/:quri \
		https://beta.quicklisp.org/archive/split-sequence/2019-05-21/:splitsequence \
		https://beta.quicklisp.org/archive/trivial-backtrace/2020-06-10/:trivialbacktrace \
		https://beta.quicklisp.org/archive/trivial-features/2020-07-15/:trivialfeatures \
		https://beta.quicklisp.org/archive/trivial-garbage/2020-09-25/:trivialgarbage \
		https://beta.quicklisp.org/archive/trivial-gray-streams/2021-01-24/:trivialgraystreams \
		https://beta.quicklisp.org/archive/trivial-utf-8/2020-09-25/:trivialutf8 \
		https://beta.quicklisp.org/archive/trivial-with-current-source-form/2020-04-27/:trivialwithcurrentsourceform \
		https://beta.quicklisp.org/archive/uax-15/2021-01-24/:uax15 \
		https://beta.quicklisp.org/archive/usocket/2019-12-27/:usocket \
		https://beta.quicklisp.org/archive/uuid/2020-07-15/:uuid \
		https://beta.quicklisp.org/archive/yason/2019-12-27/:yason \
		https://beta.quicklisp.org/archive/zs3/2019-10-07/:zs3
PKGNAMESUFFIX=	3
DISTFILES=	alexandria-20200925-git.tgz:alexandria \
		anaphora-20210124-git.tgz:anaphora \
		asdf-finalizers-20170403-git.tgz:asdffinalizers \
		asdf-system-connections-20170124-git.tgz:asdfsystemconnections \
		babel-20200925-git.tgz:babel \
		bordeaux-threads-v0.8.8.tgz:bordeauxthreads \
		buildapp-1.5.6.tgz:buildapp \
		cffi_0.23.0.tgz:cffi \
		chipz-20190202-git.tgz:chipz \
		chunga-20200427-git.tgz:chunga \
		cl-abnf-20200325-git.tgz:clabnf \
		cl-base64-20201016-git.tgz:clbase64 \
		cl-containers-20200427-git.tgz:clcontainers \
		cl-fad-20210124-git.tgz:clfad \
		cl-interpol-20201220-git.tgz:clinterpol \
		cl-log.1.0.1.tgz:cllog \
		cl-markdown-20191227-git.tgz:clmarkdown \
		cl-mssql-20210124-git.tgz:clmssql \
		cl-mustache-20200325-git.tgz:clmustache \
		cl-ppcre-20190521-git.tgz:clppcre \
		cl-sqlite-20190813-git.tgz:clsqlite \
		cl-unicode-20210124-git.tgz:clunicode \
		cl-utilities-1.2.4.tgz:clutilities \
		cl+ssl-20210124-git.tgz:clssl \
		closer-mop-20210124-git.tgz:closermop \
		closure-common-20181018-git.tgz:closurecommon \
		command-line-arguments-20200325-git.tgz:commandlinearguments \
		cxml-20200610-git.tgz:cxml \
		drakma-v2.0.7.tgz:drakma \
		dynamic-classes-20130128-git.tgz:dynamicclasses \
		esrap-20201220-git.tgz:esrap \
		flexi-streams-20200925-git.tgz:flexistreams \
		garbage-pools-20210124-git.tgz:garbagepools \
		global-vars-20141106-git.tgz:globalvars \
		ieee-floats-20170830-git.tgz:ieeefloats \
		ironclad-v0.54.tgz:ironclad \
		iterate-20200610-git.tgz:iterate \
		local-time-20210124-git.tgz:localtime \
		lparallel-20160825-git.tgz:lparallel \
		md5-20180228-git.tgz:md5 \
		metabang-bind-20200218-git.tgz:metabangbind \
		metatilities-base-20191227-git.tgz:metatilitiesbase \
		named-readtables-20210124-git.tgz:namedreadtables \
		parse-number-v1.7.tgz:parsenumber \
		postmodern-20210124-git.tgz:postmodern \
		puri-20201016-git.tgz:puri \
		py-configparser-20170830-svn.tgz:pyconfigparser \
		quri-20201220-git.tgz:quri \
		split-sequence-v2.0.0.tgz:splitsequence \
		trivial-backtrace-20200610-git.tgz:trivialbacktrace \
		trivial-features-20200715-git.tgz:trivialfeatures \
		trivial-garbage-20200925-git.tgz:trivialgarbage \
		trivial-gray-streams-20210124-git.tgz:trivialgraystreams \
		trivial-utf-8-20200925-git.tgz:trivialutf8 \
		trivial-with-current-source-form-20200427-git.tgz:trivialwithcurrentsourceform \
		uax-15-20210124-git.tgz:uax15 \
		usocket-0.8.3.tgz:usocket \
		uuid-20200715-git.tgz:uuid \
		yason-v0.7.8.tgz:yason \
		zs3-1.3.3.tgz:zs3
DIST_SUBDIR=	pgloader

MAINTAINER=	freebsd-washroom@duhanic.com
COMMENT=	Data loading and migration tool for PostgreSQL using the COPY command

LICENSE=	PostgreSQL

BUILD_DEPENDS=	sbcl:lang/sbcl
LIB_DEPENDS=	libsqlite3.so:databases/sqlite3 \
		libtdsodbc.so:databases/freetds

USES=		gmake
MY_QLB_VER=	version-2015-01-28
MY_QL_VER=	version-2021-02-13
MY_QL_SW=	build/quicklisp/dists/quicklisp/software
MY_QL_LP=	build/quicklisp/local-projects
USE_GITHUB=	yes
GH_TUPLE=	dimitri:pgloader: \
		quicklisp:quicklisp-bootstrap:${MY_QLB_VER}:qlb \
		quicklisp:quicklisp-client:${MY_QL_VER}:ql \
		qitab:qmynd:7e56daf7:qmynd/${MY_QL_LP}/qmynd \
		dimitri:cl-ixf:ed26f87e:clixf/${MY_QL_LP}/cl-ixf \
		dimitri:cl-db3:38e5ad35:cldb3/${MY_QL_LP}/cl-db3 \
		AccelerationNet:cl-csv:68ecb5d8:clcsv/${MY_QL_LP}/cl-csv

MAKE_ARGS=	CL=sbcl
MAKE_JOBS_UNSAFE=	yes
PLIST_FILES=	bin/pgloader

# don't strip away SBCL/CCL:
STRIP=

post-extract:
	${RLN} ${WRKDIR}/quicklisp-bootstrap-${MY_QLB_VER}/quicklisp.lisp ${WRKSRC}/build
	${RLN} ${WRKDIR}/quicklisp-client-${MY_QL_VER}/asdf.lisp ${WRKSRC}/build/quicklisp
	${RLN} ${WRKDIR}/quicklisp-client-${MY_QL_VER}/setup.lisp ${WRKSRC}/build/quicklisp
	${RLN} ${WRKDIR}/quicklisp-client-${MY_QL_VER}/quicklisp ${WRKSRC}/build/quicklisp
	${MKDIR} ${WRKDIR}/quicklisp-client-${MY_QL_VER}/dists/quicklisp
	${TOUCH} ${WRKDIR}/quicklisp-client-${MY_QL_VER}/dists/quicklisp/distinfo.txt
	${TOUCH} ${WRKDIR}/quicklisp-client-${MY_QL_VER}/dists/quicklisp/releases.txt
	${TOUCH} ${WRKDIR}/quicklisp-client-${MY_QL_VER}/dists/quicklisp/systems.txt
	${MKDIR} ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/alexandria-20200925-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/anaphora-20210124-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/asdf-finalizers-20170403-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/asdf-system-connections-20170124-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/babel-20200925-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/bordeaux-threads-v0.8.8 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/buildapp-1.5.6 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cffi_0.23.0 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/chipz-20190202-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/chunga-20200427-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-abnf-20200325-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-base64-20201016-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-containers-20200427-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-fad-20210124-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-interpol-20201220-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-log.1.0.1 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-markdown-20191227-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-mssql-20210124-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-mustache-20200325-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-ppcre-20190521-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-sqlite-20190813-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-unicode-20210124-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-utilities-1.2.4 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl+ssl-20210124-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/closer-mop-20210124-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/closure-common-20181018-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/command-line-arguments-20200325-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cxml-20200610-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/drakma-v2.0.7 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/dynamic-classes-20130128-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/esrap-20201220-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/flexi-streams-20200925-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/garbage-pools-20210124-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/global-vars-20141106-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/ieee-floats-20170830-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/ironclad-v0.54 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/iterate-20200610-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/local-time-20210124-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/lparallel-20160825-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/md5-20180228-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/metabang-bind-20200218-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/metatilities-base-20191227-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/named-readtables-20210124-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/parse-number-v1.7 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/postmodern-20210124-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/puri-20201016-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/py-configparser-20170830-svn ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/quri-20201220-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/split-sequence-v2.0.0 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/trivial-backtrace-20200610-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/trivial-features-20200715-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/trivial-garbage-20200925-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/trivial-gray-streams-20210124-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/trivial-utf-8-20200925-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/trivial-with-current-source-form-20200427-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/uax-15-20210124-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/usocket-0.8.3 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/uuid-20200715-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/yason-v0.7.8 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/zs3-1.3.3 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/buildapp-1.5.6 ${WRKSRC}/${MY_QL_LP}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/pgloader ${STAGEDIR}${PREFIX}/bin/pgloader

.include <bsd.port.mk>
