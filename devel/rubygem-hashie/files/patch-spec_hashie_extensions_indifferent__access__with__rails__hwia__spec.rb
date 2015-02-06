--- spec/hashie/extensions/indifferent_access_with_rails_hwia_spec.rb.orig	2015-02-06 12:45:47 UTC
+++ spec/hashie/extensions/indifferent_access_with_rails_hwia_spec.rb
@@ -1,8 +1,9 @@
 # This set of tests verifies that Hashie::Extensions::IndifferentAccess works with
 # ActiveSupport HashWithIndifferentAccess hashes. See #164 and #166 for details.
 
-require 'spec_helper'
 require 'active_support/hash_with_indifferent_access'
+require 'active_support/core_ext/hash'
+require 'spec_helper'
 
 describe Hashie::Extensions::IndifferentAccess do
   class IndifferentHashWithMergeInitializer < Hash
@@ -35,6 +36,10 @@ describe Hashie::Extensions::Indifferent
     include Hashie::Extensions::MergeInitializer
   end
 
+  class MashWithIndifferentAccess < Hashie::Mash
+    include Hashie::Extensions::IndifferentAccess
+  end
+
   shared_examples_for 'hash with indifferent access' do
     it 'is able to access via string or symbol' do
       indifferent_hash = ActiveSupport::HashWithIndifferentAccess.new(abc: 123)
@@ -193,4 +198,11 @@ describe Hashie::Extensions::Indifferent
       expect(instance[:foo]).to be_a(ActiveSupport::HashWithIndifferentAccess)
     end
   end
+
+  describe 'Mash with indifferent access' do
+    it 'is able to be created for a deep nested HashWithIndifferentAccess' do
+      indifferent_hash = ActiveSupport::HashWithIndifferentAccess.new(abc: { def: 123 })
+      MashWithIndifferentAccess.new(indifferent_hash)
+    end
+  end
 end
