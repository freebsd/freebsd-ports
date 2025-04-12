PORTNAME=	pgloader
PORTVERSION=	3.6.9
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
MASTER_SITES=	https://beta.quicklisp.org/archive/alexandria/2023-10-21/:alexandria \
		https://beta.quicklisp.org/archive/anaphora/2022-02-20/:anaphora \
		https://beta.quicklisp.org/archive/asdf-finalizers/2022-11-06/:asdffinalizers \
		https://beta.quicklisp.org/archive/asdf-system-connections/2017-01-24/:asdfsystemconnections \
		https://beta.quicklisp.org/archive/babel/2023-02-14/:babel \
		https://beta.quicklisp.org/archive/bordeaux-threads/2023-10-21/:bordeauxthreads \
		https://beta.quicklisp.org/archive/buildapp/2015-12-18/:buildapp \
		https://beta.quicklisp.org/archive/cffi/2023-10-21/:cffi \
		https://beta.quicklisp.org/archive/chipz/2023-06-18/:chipz \
		https://beta.quicklisp.org/archive/chunga/2023-10-21/:chunga \
		https://beta.quicklisp.org/archive/cl-base64/2020-10-16/:clbase64 \
		https://beta.quicklisp.org/archive/cl-containers/2023-10-21/:clcontainers \
		https://beta.quicklisp.org/archive/cl-csv/2020-10-16/:clcsv \
		https://beta.quicklisp.org/archive/cl-db3/2020-02-18/:cldb3 \
		https://beta.quicklisp.org/archive/cl-fad/2022-02-20/:clfad \
		https://beta.quicklisp.org/archive/cl-interpol/2022-11-06/:clinterpol \
		https://beta.quicklisp.org/archive/cl-ixf/2018-02-28/:clixf \
		https://beta.quicklisp.org/archive/cl-log/2013-01-28/:cllog \
		https://beta.quicklisp.org/archive/cl-markdown/2019-12-27/:clmarkdown \
		https://beta.quicklisp.org/archive/cl-mssql/2021-01-24/:clmssql \
		https://beta.quicklisp.org/archive/cl-mustache/2020-03-25/:clmustache \
		https://beta.quicklisp.org/archive/cl-ppcre/2023-06-18/:clppcre \
		https://beta.quicklisp.org/archive/cl-sqlite/2019-08-13/:clsqlite \
		https://beta.quicklisp.org/archive/cl-unicode/2021-02-28/:clunicode \
		https://beta.quicklisp.org/archive/cl-utilities/2010-10-06/:clutilities \
		https://beta.quicklisp.org/archive/cl+ssl/2023-10-21/:clssl \
		https://beta.quicklisp.org/archive/closer-mop/2023-10-21/:closermop \
		https://beta.quicklisp.org/archive/closure-common/2018-10-18/:closurecommon \
		https://beta.quicklisp.org/archive/command-line-arguments/2021-08-07/:commandlinearguments \
		https://beta.quicklisp.org/archive/cxml/2020-06-10/:cxml \
		https://beta.quicklisp.org/archive/drakma/2023-10-21/:drakma \
		https://beta.quicklisp.org/archive/dynamic-classes/2023-10-21/:dynamicclasses \
		https://beta.quicklisp.org/archive/esrap/2023-06-18/:esrap \
		https://beta.quicklisp.org/archive/flexi-streams/2022-02-20/:flexistreams \
		https://beta.quicklisp.org/archive/garbage-pools/2021-01-24/:garbagepools \
		https://beta.quicklisp.org/archive/global-vars/2014-11-06/:globalvars \
		https://beta.quicklisp.org/archive/ieee-floats/2022-02-20/:ieeefloats \
		https://beta.quicklisp.org/archive/ironclad/2023-10-21/:ironclad \
		https://beta.quicklisp.org/archive/iterate/2021-05-31/:iterate \
		https://beta.quicklisp.org/archive/local-time/2023-10-21/:localtime \
		https://beta.quicklisp.org/archive/lparallel/2016-08-25/:lparallel \
		https://beta.quicklisp.org/archive/md5/2021-06-30/:md5 \
		https://beta.quicklisp.org/archive/metabang-bind/2023-06-18/:metabangbind \
		https://beta.quicklisp.org/archive/metatilities-base/2019-12-27/:metatilitiesbase \
		https://beta.quicklisp.org/archive/mgl-pax/2023-10-21/:mglpax \
		https://beta.quicklisp.org/archive/named-readtables/2023-10-21/:namedreadtables \
		https://beta.quicklisp.org/archive/parse-number/2018-02-28/:parsenumber \
		https://beta.quicklisp.org/archive/postmodern/2023-10-21/:postmodern \
		https://beta.quicklisp.org/archive/puri/2020-10-16/:puri \
		https://beta.quicklisp.org/archive/py-configparser/2017-08-30/:pyconfigparser \
		https://beta.quicklisp.org/archive/qmynd/2019-07-10/:qmynd \
		https://beta.quicklisp.org/archive/quri/2023-06-18/:quri \
		https://beta.quicklisp.org/archive/salza2/2021-10-20/:salza2 \
		https://beta.quicklisp.org/archive/split-sequence/2021-05-31/:splitsequence \
		https://beta.quicklisp.org/archive/trivial-backtrace/2023-02-14/:trivialbacktrace \
		https://beta.quicklisp.org/archive/trivial-features/2023-06-18/:trivialfeatures \
		https://beta.quicklisp.org/archive/trivial-garbage/2023-10-21/:trivialgarbage \
		https://beta.quicklisp.org/archive/trivial-gray-streams/2023-10-21/:trivialgraystreams \
		https://beta.quicklisp.org/archive/trivial-utf-8/2023-10-21/:trivialutf8 \
		https://beta.quicklisp.org/archive/trivial-with-current-source-form/2023-06-18/:trivialwithcurrentsourceform \
		https://beta.quicklisp.org/archive/uax-15/2022-11-06/:uax15 \
		https://beta.quicklisp.org/archive/usocket/2023-06-18/:usocket \
		https://beta.quicklisp.org/archive/uuid/2020-07-15/:uuid \
		https://beta.quicklisp.org/archive/yason/2023-02-14/:yason \
		https://beta.quicklisp.org/archive/zs3/2019-10-07/:zs3
PKGNAMESUFFIX=	3
DISTFILES=	alexandria-20231021-git.tgz:alexandria \
		anaphora-20220220-git.tgz:anaphora \
		asdf-finalizers-20221106-git.tgz:asdffinalizers \
		asdf-system-connections-20170124-git.tgz:asdfsystemconnections \
		babel-20230214-git.tgz:babel \
		bordeaux-threads-v0.9.3.tgz:bordeauxthreads \
		buildapp-1.5.6.tgz:buildapp \
		cffi-20231021-git.tgz:cffi \
		chipz-20230618-git.tgz:chipz \
		chunga-20231021-git.tgz:chunga \
		cl-base64-20201016-git.tgz:clbase64 \
		cl-containers-20231021-git.tgz:clcontainers \
		cl-csv-20201016-git.tgz:clcsv \
		cl-db3-20200218-git.tgz:cldb3 \
		cl-fad-20220220-git.tgz:clfad \
		cl-interpol-20221106-git.tgz:clinterpol \
		cl-ixf-20180228-git.tgz:clixf \
		cl-log.1.0.1.tgz:cllog \
		cl-markdown-20191227-git.tgz:clmarkdown \
		cl-mssql-20210124-git.tgz:clmssql \
		cl-mustache-20200325-git.tgz:clmustache \
		cl-ppcre-20230618-git.tgz:clppcre \
		cl-sqlite-20190813-git.tgz:clsqlite \
		cl-unicode-20210228-git.tgz:clunicode \
		cl-utilities-1.2.4.tgz:clutilities \
		cl+ssl-20231021-git.tgz:clssl \
		closer-mop-20231021-git.tgz:closermop \
		closure-common-20181018-git.tgz:closurecommon \
		command-line-arguments-20210807-git.tgz:commandlinearguments \
		cxml-20200610-git.tgz:cxml \
		drakma-v2.0.10.tgz:drakma \
		dynamic-classes-20231021-git.tgz:dynamicclasses \
		esrap-20230618-git.tgz:esrap \
		flexi-streams-20220220-git.tgz:flexistreams \
		garbage-pools-20210124-git.tgz:garbagepools \
		global-vars-20141106-git.tgz:globalvars \
		ieee-floats-20220220-git.tgz:ieeefloats \
		ironclad-v0.59.tgz:ironclad \
		iterate-release-b0f9a9c6-git.tgz:iterate \
		local-time-20231021-git.tgz:localtime \
		lparallel-20160825-git.tgz:lparallel \
		md5-20210630-git.tgz:md5 \
		metabang-bind-20230618-git.tgz:metabangbind \
		metatilities-base-20191227-git.tgz:metatilitiesbase \
		mgl-pax-20231021-git.tgz:mglpax \
		named-readtables-20231021-git.tgz:namedreadtables \
		parse-number-v1.7.tgz:parsenumber \
		postmodern-20231021-git.tgz:postmodern \
		puri-20201016-git.tgz:puri \
		py-configparser-20170830-svn.tgz:pyconfigparser \
		qmynd-20190710-git.tgz:qmynd \
		quri-20230618-git.tgz:quri \
		salza2-2.1.tgz:salza2 \
		split-sequence-v2.0.1.tgz:splitsequence \
		trivial-backtrace-20230214-git.tgz:trivialbacktrace \
		trivial-features-20230618-git.tgz:trivialfeatures \
		trivial-garbage-20231021-git.tgz:trivialgarbage \
		trivial-gray-streams-20231021-git.tgz:trivialgraystreams \
		trivial-utf-8-20231021-git.tgz:trivialutf8 \
		trivial-with-current-source-form-20230618-git.tgz:trivialwithcurrentsourceform \
		uax-15-20221106-git.tgz:uax15 \
		usocket-0.8.6.tgz:usocket \
		uuid-20200715-git.tgz:uuid \
		yason-20230214-git.tgz:yason \
		zs3-1.3.3.tgz:zs3
DIST_SUBDIR=	pgloader

MAINTAINER=	freebsd-washroom@duhanic.com
COMMENT=	Data loading and migration tool for PostgreSQL using the COPY command
WWW=		https://pgloader.io

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
	${RLN} ${WRKDIR}/alexandria-20231021-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/anaphora-20220220-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/asdf-finalizers-20221106-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/asdf-system-connections-20170124-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/babel-20230214-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/bordeaux-threads-v0.9.3 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/buildapp-1.5.6 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cffi-20231021-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/chipz-20230618-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/chunga-20231021-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-base64-20201016-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-containers-20231021-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-csv-20201016-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-db3-20200218-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-fad-20220220-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-interpol-20221106-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-ixf-20180228-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-log.1.0.1 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-markdown-20191227-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-mssql-20210124-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-mustache-20200325-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-ppcre-20230618-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-sqlite-20190813-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-unicode-20210228-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl-utilities-1.2.4 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cl+ssl-20231021-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/closer-mop-20231021-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/closure-common-20181018-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/command-line-arguments-20210807-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/cxml-20200610-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/drakma-v2.0.10 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/dynamic-classes-20231021-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/esrap-20230618-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/flexi-streams-20220220-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/garbage-pools-20210124-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/global-vars-20141106-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/ieee-floats-20220220-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/ironclad-v0.59 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/iterate-release-b0f9a9c6-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/local-time-20231021-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/lparallel-20160825-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/md5-20210630-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/metabang-bind-20230618-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/metatilities-base-20191227-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/mgl-pax-20231021-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/named-readtables-20231021-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/parse-number-v1.7 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/postmodern-20231021-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/puri-20201016-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/py-configparser-20170830-svn ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/qmynd-20190710-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/quri-20230618-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/salza2-2.1 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/split-sequence-v2.0.1 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/trivial-backtrace-20230214-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/trivial-features-20230618-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/trivial-garbage-20231021-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/trivial-gray-streams-20231021-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/trivial-utf-8-20231021-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/trivial-with-current-source-form-20230618-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/uax-15-20221106-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/usocket-0.8.6 ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/uuid-20200715-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/yason-20230214-git ${WRKSRC}/${MY_QL_SW}
	${RLN} ${WRKDIR}/zs3-1.3.3 ${WRKSRC}/${MY_QL_SW}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/pgloader ${STAGEDIR}${PREFIX}/bin/pgloader

.include <bsd.port.mk>
